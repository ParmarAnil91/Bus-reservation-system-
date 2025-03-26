#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 10

typedef struct {
    int seatNumber;
    int isBooked;
    char passengerName[50];
} Seat;

typedef struct {
    char busNumber[10];
    char driverName[50];
    char destination[50];
    Seat seats[MAX_SEATS];
} Bus;

void initializeBus(Bus *bus) {
    strcpy(bus->busNumber, "BUS123");
    strcpy(bus->driverName, "John Doe");
    strcpy(bus->destination, "City Center");
    
    for (int i = 0; i < MAX_SEATS; i++) {
        bus->seats[i].seatNumber = i + 1;
        bus->seats[i].isBooked = 0;
        strcpy(bus->seats[i].passengerName, "");
    }
}

void displaySeats(Bus bus) {
    printf("\nSeat Availability:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", bus.seats[i].seatNumber, bus.seats[i].isBooked ? "Booked" : "Available");
    }
}

void bookSeat(Bus *bus) {
    int seatNum;
    char name[50];

    displaySeats(*bus);
    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS || bus->seats[seatNum - 1].isBooked) {
        printf("Invalid or already booked seat!\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf(" %[^\n]", name);

    bus->seats[seatNum - 1].isBooked = 1;
    strcpy(bus->seats[seatNum - 1].passengerName, name);

    printf("Seat %d booked successfully for %s!\n", seatNum, name);
}

void cancelReservation(Bus *bus) {
    int seatNum;
    displaySeats(*bus);
    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS || !bus->seats[seatNum - 1].isBooked) {
        printf("Invalid or not booked seat!\n");
        return;
    }

    bus->seats[seatNum - 1].isBooked = 0;
    strcpy(bus->seats[seatNum - 1].passengerName, "");

    printf("Reservation for seat %d canceled successfully!\n", seatNum);
}

void displayBusDetails(Bus bus) {
    printf("\nBus Details:\n");
    printf("Bus Number: %s\n", bus.busNumber);
    printf("Driver Name: %s\n", bus.driverName);
    printf("Destination: %s\n", bus.destination);
    displaySeats(bus);
}

int main() {
    Bus bus;
    initializeBus(&bus);

    int choice;
    while (1) {
        printf("\n--- Bus Reservation System ---\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Reservation\n");
        printf("4. Display Bus Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(bus);
                break;
            case 2:
                bookSeat(&bus);
                break;
            case 3:
                cancelReservation(&bus);
                break;
            case 4:
                displayBusDetails(bus);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}