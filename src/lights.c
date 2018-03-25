#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ulfius.h>
#include <jansson.h>

int lights_on(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    json_t *reqData = ulfius_get_json_body_request(request, NULL);
    if (!json_is_object(reqData))
    {
        fprintf(stderr, "Data is not an object.");
        json_decref(reqData);
        ulfius_set_string_body_response(response, 500, "Error encediendo luz");
        return U_CALLBACK_CONTINUE;
    }
    int lightNum = json_integer_value(reqData);
    char buffer[12];
    sprintf(buffer, "%d", lightNum);
    puts(buffer);
    switch (lightNum)
    {
    case 1:
        puts("Luz 1 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    case 2:
        puts("Luz 2 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    case 3:
        puts("Luz 3 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    case 4:
        puts("Luz 4 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    case 5:
        puts("Luz 5 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    }
    return U_CALLBACK_CONTINUE; 
}