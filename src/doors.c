#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ulfius.h>
#include <jansson.h>

// DOORS: THIS WILL CHANGE
int door1 = 0;
int door2 = 0;
int door3 = 0;
int door4 = 0;

int door_state(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    json_t *req_data = ulfius_get_json_body_request(request, NULL), *result, *value;
    result = json_object();
    value = json_integer(0);
    if (!json_is_object(req_data)) // Checks if recieved data is empty.
    {
        fprintf(stderr, "Data is not an object.");
        json_decref(req_data);
        ulfius_set_string_body_response(response, 500, "Error obteniendo estado de la puerta");
        return U_CALLBACK_CONTINUE;
    }
    json_t *door_data = json_object_get(req_data, "door"); // Gets the "door" attribute as a JSON object.
    int door_num = json_integer_value(door_data);          // Converts the "door" JSON object to an integer.
    switch (door_num)
    {
    case 1:
        json_integer_set(value, door1);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 2:
        json_integer_set(value, door2);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 3:
        json_integer_set(value, door3);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 4:
        json_integer_set(value, door4);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    }
    json_decref(req_data);
    json_decref(result);
    json_decref(value);
    json_decref(door_data);
    return U_CALLBACK_CONTINUE;
}