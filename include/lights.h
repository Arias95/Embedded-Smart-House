#ifndef _LIGHTS_H
#define _LIGHTS_H

int lights_on(const struct _u_request *, struct _u_response *, void *);
int lights_off(const struct _u_request *, struct _u_response *, void *);
int light_state(const struct _u_request *, struct _u_response *, void *);

#endif