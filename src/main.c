#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <poll.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>

#include <cjson/cJSON.h>

// include/data
#include "data/constants.h"
#include "data/data_structures.h"

// include/helpers
#include "helpers/array_handling.h"
#include "helpers/json_handling.h"
#include "helpers/hyprland_struct_handling.h"

// include/utils
#include "utils/hyprland_socket_handling.h"

int main() {
    SocketData * events_data = create_socket_data();
    grab_information_from_hyprland_socket(SOCKET2, events_data);
    
    int ret;

    while (1) {
        // Call poll() to check for events on the socket
        ret = poll(events_data->poll_descriptor, 1, -1); // -1 means wait indefinitely
        if (ret == -1) {
            perror("poll");
            close(events_data->poll_descriptor->fd);
            exit(EXIT_FAILURE);
        }
        if (events_data->poll_descriptor->revents & POLLIN) {
            // Data is ready to read from the socket
            ssize_t bytes_received = recv(events_data->poll_descriptor->fd, events_data->data_received, MAX_BUFFER_SIZE + 1, 0);
            if (bytes_received == -1) {
                perror("recv");
                close(events_data->poll_descriptor->fd);
                exit(EXIT_FAILURE);
            } else if (bytes_received == 0) {
                // Connection closed by the other end
                printf("Connection closed by the server.\n");
                break;
            }

            // Process the received data
            events_data->data_received[bytes_received] = '\0';
            char * search_string_workspace = "workspace>>";
            char * search_string_focusedmon = "focusedmon>>";
            if (strstr(events_data->data_received, search_string_workspace) || strstr(events_data->data_received, search_string_focusedmon)) {
                initialize_and_print_workspace_info_as_json();
            }
            fflush(stdout);
        }
    }

    close(events_data->poll_descriptor->fd);

    return 0;
}

