 #include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    // Initializing syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        fprintf(stderr, "Error: Two arguments required.\n");
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Logging for write operation
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    FILE *fp = fopen(writefile, "w");
    if (!fp) {
        syslog(LOG_ERR, "Error opening file '%s': %m", writefile);
        perror("Error opening file");
        closelog();
        return 1;
    }

    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error writing to file '%s': %m", writefile);
        perror("Error writing to file");
        fclose(fp);
        closelog();
        return 1;
    }

    fclose(fp);
    closelog();
    return 0;
}
