// data_structures.h

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cjson/cJSON.h>

#include <stdint.h>

#include <poll.h>

typedef struct {
    cJSON * monitors;
    cJSON * workspaces;
    cJSON * activeworkspace;

    int monitors_length;
    int workspaces_length;

    //bool (*workspace_array)[WORKSPACES_AMOUNT];
    //bool (*activeworkspace_array)[WORKSPACES_AMOUNT];
    
    uint16_t * workspace_array;
    uint16_t * activeworkspace_array;
} HyprlandData;

struct pollfd;

typedef struct {
    char * data_received;
    struct pollfd *poll_descriptor;
} SocketData;

#endif