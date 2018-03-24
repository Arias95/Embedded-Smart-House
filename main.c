#define U_DISABLE_CURL
#define U_DISABLE_WEBSOCKET
#include <stdio.h>
#include <unistd.h>
#include <ulfius.h>
#include <jansson.h>
#include <errno.h>
#include "include/photo.h"

#define PORT 8000

int main(void)
{
    struct _u_instance instance;

    if (ulfius_init_instance(&instance, PORT, NULL, NULL))
    {
        fprintf(stderr, "Error inicializando REST, abortando...\n");
        return (1);
    }

    ulfius_add_endpoint_by_val(&instance, "GET", "/foto", NULL, 0, &photo_take, NULL);

    if (ulfius_start_framework(&instance) == U_OK)
    {
        printf("REST inicializado en el puerto %d\n", instance.port);
        getchar();
    }
    else
    {
        fprintf(stderr, "Error inicializando REST, abortando...\n");
    }
    printf("REST finalizado\n");

    ulfius_stop_framework(&instance);
    ulfius_clean_instance(&instance);

    return 0;
}