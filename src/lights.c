#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ulfius.h>
#include <jansson.h>

// LIGHT EXAMPLES: THIS WILL CHANGE
int light1 = 0;
int light2 = 0;
int light3 = 0;
int light4 = 0;
int light5 = 0;

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
    int light_num = json_integer_value(light_data);          // Converts the "light" JSON object to an integer.
    switch (light_num)
    {
    case 1:
        light1 = 1;
        printf("Luz 1: %d\n", light1);
        ulfius_set_string_body_response(response, 200, "Encendida luz 1.\n");
        break;
    case 2:
        light2 = 1;
        printf("Luz 2: %d\n", light2);
        ulfius_set_string_body_response(response, 200, "Encendida luz 2.\n");
        break;
    case 3:
        light3 = 1;
        printf("Luz 3: %d\n", light3);
        ulfius_set_string_body_response(response, 200, "Encendida luz 3.\n");
        break;
    case 4:
        light4 = 1;
        printf("Luz 4: %d\n", light4);
        ulfius_set_string_body_response(response, 200, "Encendida luz 4.\n");
        break;
    case 5:
        light5 = 1;
        printf("Luz 5: %d\n", light5);
        ulfius_set_string_body_response(response, 200, "Encendida luz 5.\n");
        break;
    }
    // Cleaning memory data:
    json_decref(req_data);
    json_decref(light_data);
    return U_CALLBACK_CONTINUE;
}

int lights_off(const struct _u_request *request, struct _u_response *response, void *user_data)
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
    int light_num = json_integer_value(light_data);          // Converts the "light" JSON object to an integer.
    switch (light_num)
    {
    case 1:
        light1 = 0;
        printf("Luz 1: %d\n", light1);
        ulfius_set_string_body_response(response, 200, "Apagada luz 1.\n");
        break;
    case 2:
        light2 = 0;
        printf("Luz 2: %d\n", light2);
        ulfius_set_string_body_response(response, 200, "Apagada luz 2.\n");
        break;
    case 3:
        light3 = 0;
        printf("Luz 3: %d\n", light3);
        ulfius_set_string_body_response(response, 200, "Apagada luz 3.\n");
        break;
    case 4:
        light4 = 0;
        printf("Luz 4: %d\n", light4);
        ulfius_set_string_body_response(response, 200, "Apagada luz 4.\n");
        break;
    case 5:
        light5 = 0;
        printf("Luz 5: %d\n", light5);
        ulfius_set_string_body_response(response, 200, "Apagada luz 5.\n");
        break;
    }
    // Cleaning memory data:
    json_decref(req_data);
    json_decref(light_data);
    return U_CALLBACK_CONTINUE;
}

int light_state(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    json_t *req_data = ulfius_get_json_body_request(request, NULL), *result, *value;
    result = json_object();
    value = json_integer(0);
    if (!json_is_object(req_data)) // Checks if recieved data is empty.
    {
        fprintf(stderr, "Data is not an object.");
        json_decref(req_data);
        ulfius_set_string_body_response(response, 500, "Error encediendo luz");
        return U_CALLBACK_CONTINUE;
    }
    json_t *light_data = json_object_get(req_data, "light"); // Gets the "light" attribute as a JSON object.
    int light_num = json_integer_value(light_data);          // Converts the "light" JSON object to an integer.

    switch (light_num)
    {
    case 1:
        json_integer_set(value, light1);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 2:
        json_integer_set(value, light2);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 3:
        json_integer_set(value, light3);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 4:
        json_integer_set(value, light4);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    case 5:
        json_integer_set(value, light5);
        json_object_set(result, "status:", value);
        ulfius_set_json_body_response(response, 200, result);
        break;
    }
    json_decref(req_data);
    json_decref(result);
    json_decref(value);
    json_decref(light_data);
    return U_CALLBACK_CONTINUE;
}