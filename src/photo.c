#define STATIC_FILE_CHUNK 25
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ulfius.h>
#include <jansson.h>
#include <orcania.h>
#include <yder.h>

struct _static_file_config
{
    char *files_path;
    char *url_prefix;
    struct _u_map *mime_types;
};

/**
 * Return the filename extension
 */
const char *get_filename_ext(const char *path)
{
    const char *dot = strrchr(path, '.');
    if (!dot || dot == path)
        return "*";
    if (strchr(dot, '?') != NULL)
    {
        *strchr(dot, '?') = '\0';
    }
    return dot;
}

/**
 * Streaming callback function to ease sending large files
 */
static ssize_t callback_static_file_stream(void *cls, uint64_t pos, char *buf, size_t max)
{
    if (cls != NULL)
    {
        return fread(buf, 1, max, (FILE *)cls);
    }
    else
    {
        return U_STREAM_END;
    }
}

/**
 * Cleanup FILE* structure when streaming is complete
 */
static void callback_static_file_stream_free(void *cls)
{
    if (cls != NULL)
    {
        fclose((FILE *)cls);
    }
}

int photo_take(const struct _u_request *request, struct _u_response *response, void *user_data)
{
    size_t length;
    FILE *f;
    char *file_path = "/home/andres/Documents/Embebidos/Embedded-Smart-House/image.jpeg";
    const char *content_type;
    //char cwd[1024];
    system("fswebcam image.jpeg");

    if (response->shared_data != NULL)
    {
        return U_CALLBACK_CONTINUE;
    }

    puts(file_path);
    if (access(file_path, F_OK) != -1)
    {
        f = fopen(file_path, "rb");
        if (f)
        {
            fseek(f, 0, SEEK_END);
            length = ftell(f);
            fseek(f, 0, SEEK_SET);
            content_type = "image/jpeg";
            u_map_put(response->map_header, "Content-Type:", content_type);
            u_map_put(response->map_header, "Cache-Control:", "public, max-age=31536000");

            if (ulfius_set_stream_response(response, 200, &callback_static_file_stream, &callback_static_file_stream_free, length, STATIC_FILE_CHUNK, f) != U_OK)
            {
                y_log_message(Y_LOG_LEVEL_ERROR, "callback_static_file - Error ulfius_set_stream_response");
            }
        }
        else
        {
            ulfius_set_string_body_response(response, 404, "File not found");
        }
        //o_free(file_path);
        return U_CALLBACK_CONTINUE;
    }
    else
    {
        y_log_message(Y_LOG_LEVEL_ERROR, "Static File Server - Error, user_data is NULL or inconsistent");
        return U_CALLBACK_ERROR;
    }

    return U_CALLBACK_CONTINUE;
}