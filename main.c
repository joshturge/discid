#include <discid/discid.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DiscId *disc = discid_new();
    char *device = NULL;

    // If args use [1] as device 
    if (argc > 1) {
		device = argv[1];
	}

    // Read the disc's TOC and check for errors
    if (discid_read_sparse(disc, device, 0) == 0) {
        fprintf(stderr, "Error: %s\n", discid_get_error_msg(disc));
        discid_free(disc);
        return 1;
    }

    printf("%s\n", discid_get_id(disc));
    discid_free(disc);
    return 0;
}