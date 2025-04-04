#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"  // Use full path

char ssid[] = "XXXXX";     // Fix SSID (hyphen instead of underscore)
char pass[] = "XXXXX";

int main() {
    stdio_init_all();  // Initialize stdio for printf

    if (cyw43_arch_init()) {  // Use default init instead of country-specific
        printf("Wi-Fi init failed\n");
        return 1;
    }
    printf("initialised\n");
    
    cyw43_arch_enable_sta_mode();
    
    printf("Connecting to Wi-Fi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect\n");
        return 1;
    }
    printf("Connected!\n");

    // Print IP address (optional)
    uint8_t *ip = (uint8_t*)&cyw43_state.netif[0].ip_addr.addr;
    printf("IP: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);

    while (true) {  // Keep program running
        sleep_ms(1000);
    }
}
