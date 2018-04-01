#ifndef PHOTO_H
#define PHOTO_H

const char * get_filename_ext(const char path);
ssize_t callback_static_file_stream(void *, uint64_t, char *, size_t);
int photo_take(const struct _u_request *, struct _u_response *, void *);

#endif