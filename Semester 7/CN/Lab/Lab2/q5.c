#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *stat_file;
    char line[256];
    char cpu[10];
    long int user, nice, system, idle, iowait, irq, softirq;
    long int prev_idle, prev_total;
    float cpu_percentage;

    while (1) {
        stat_file = fopen("/proc/stat", "r");
        if (stat_file == NULL) {
            perror("Error opening /proc/stat");
            return 1;
        }

        fgets(line, sizeof(line), stat_file);

        sscanf(line, "%s %ld %ld %ld %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq);

        long int total = user + nice + system + idle + iowait + irq + softirq;

        if (prev_total != 0) {
            cpu_percentage = ((float)(total - prev_total - (idle - prev_idle)) / (total - prev_total)) * 100.0;
            printf("Average CPU Utilization: %.2f%%\n", cpu_percentage);
        }

        prev_idle = idle;
        prev_total = total;

        fclose(stat_file);

        sleep(1);
    }

    return 0;
}
