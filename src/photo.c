#include <stdio.h>
#include <unistd.h>
#include <ulfius.h>
#include <jansson.h>

int photo_take(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    system("fswebcam image.jpeg");

    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        json_t *res = json_object();
        json_object_set_new(res, "Salio", json_string("Guapo ;)"));
        json_object_set_new(res, "Path", json_string(cwd));
        ulfius_set_json_body_response(response, 200, res);
        json_decref(res);
    }
    else
    {
        ulfius_set_string_body_response(response, 500, "Error sacando el path.");
    }

    return U_CALLBACK_CONTINUE;
}