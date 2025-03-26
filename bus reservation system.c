#include <stdio.h>

#define MAX_SEATS 5  // Number of seats available

int seats[MAX_SEATS] = {0};  // 0 means available, 1 means booked

// Function to display available seats
void showSeats() {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

// Function to book a seat
void bookSeat() {
    int seatNum;
    showSeats();
    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > MAX_SEATS || seats[seatNum - 1] == 1) {
        printf("Invalid or already booked seat!\n");
    } else {
        seats[seatNum - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNum);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Bus Reservation ---\n");
        printf("1. View Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showSeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
