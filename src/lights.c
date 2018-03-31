#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ulfius.h>
#include <jansson.h>

int lights_on(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    json_t *req_data = ulfius_get_json_body_request(request, NULL);
    if (!json_is_object(req_data)) // Checks if recieved data is empty.
    {
        fprintf(stderr, "Data is not an object.");
        json_decref(req_data);
        ulfius_set_string_body_response(response, 500, "Error encediendo luz");
        return U_CALLBACK_CONTINUE;
    }
    json_t *light_data = json_object_get(req_data, "light"); // Gets the "light" attribute as a JSON object.
    int lightNum = json_integer_value(light_data); // Converts the "light" JSON object to an integer.
    switch (lightNum)
    {
    case 1:
        puts("Luz 1 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.");
        break;
    case 2:
        puts("Luz 2 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 2.");
        break;
    case 3:
        puts("Luz 3 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 3.");
        break;
    case 4:
        puts("Luz 4 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 4.");
        break;
    case 5:
        puts("Luz 5 encendida");
        ulfius_set_string_body_response(response, 200, "Encendida luz 5.");
        break;
    }
    // Cleaning memory data:
    json_decref(req_data);
    json_decref(light_data);
    return U_CALLBACK_CONTINUE;
}