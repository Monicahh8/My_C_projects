#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h> // For IP header
#include <netinet/tcp.h> // For TCP header

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *iph = (struct ip *)(packet + 14); // Skip Ethernet header
    printf("Captured a packet:\n");
    printf("Source IP: %s\n", inet_ntoa(iph->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(iph->ip_dst));
    printf("Protocol: %d\n", iph->ip_p);
    printf("------------------------------\n");
}

int main() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE]; // Corrected line

    // Find all devices to sniff on
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    // Use the first device
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found.\n");
        pcap_freealldevs(alldevs);
        return 1;
    }
    printf("Using device: %s\n", device->name);

    // Open the device for sniffing
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 2;
    }

    // Start packet capture
    pcap_loop(handle, 10, packet_handler, NULL); // Capture 10 packets

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}