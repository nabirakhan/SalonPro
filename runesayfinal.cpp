#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a service
struct Service {
    char name[100];
    int price;
};

// Define a structure for staff members
struct Staff {
    char name[100];
    float salary;
    char skill[100];
    int availability; // 1 if available, 0 if not available
};

// Function to initialize the services array
struct Service* initializeServices() {
    struct Service* services = (struct Service*)malloc(14 * sizeof(struct Service));

    if (services == NULL) {
        perror("Error allocating memory for services");
        exit(EXIT_FAILURE);
    }

    // Assign initial data to services
    strcpy(services[0].name, "Manicure");
    services[0].price = 20;

    strcpy(services[1].name, "Pedicure");
    services[1].price = 35;

    strcpy(services[2].name, "Shampoo & Blowout");
    services[2].price = 42;

    strcpy(services[3].name, "Haircut");
    services[3].price = 98;

    strcpy(services[4].name, "Hair Color - Root Touch-Up");
    services[4].price = 67;

    strcpy(services[5].name, "Hair Color - Full HighLights");
    services[5].price = 135;

    strcpy(services[6].name, "Hair Color - Balayage/Ombre");
    services[6].price = 250;

    strcpy(services[7].name, "Hair Styling - Updo/Event Styling");
    services[7].price = 65;

    strcpy(services[8].name, "Hair Styling - Extensions");
    services[8].price = 670;

    strcpy(services[9].name, "Waxing - Facial");
    services[9].price = 20;

    strcpy(services[10].name, "Waxing - Bikini");
    services[10].price = 45;

    strcpy(services[11].name, "Waxing - Full Body");
    services[11].price = 80;

    strcpy(services[12].name, "Makeup - Everyday/Party");
    services[12].price = 60;

    strcpy(services[13].name, "Makeup - Bridal");
    services[13].price = 250;

    return services;
}

// Function to free memory allocated for services
void freeServices(struct Service* services) {
    free(services);
}

// Function to initialize the staffList array
struct Staff* initializeStaffList() {
    struct Staff* staffList = (struct Staff*)malloc(5 * sizeof(struct Staff));

    if (staffList == NULL) {
        printf("Error allocating memory for staffList");
        exit(EXIT_FAILURE);
    }

    // Assign initial data to staffList
    strcpy(staffList[0].name, "Nabira Khan");
    staffList[0].salary = 5000.0;
    strcpy(staffList[0].skill, "Hair Stylist");
    staffList[0].availability = 1;

    strcpy(staffList[1].name, "Omaima");
    staffList[1].salary = 4500.0;
    strcpy(staffList[1].skill, "Manicurist");
    staffList[1].availability = 1;

    strcpy(staffList[2].name, "Aiman Nadeem");
    staffList[2].salary = 6000.0;
    strcpy(staffList[2].skill, "Color Special");
    staffList[2].availability = 1;

    strcpy(staffList[3].name, "Aisha Asif");
    staffList[3].salary = 5500.0;
    strcpy(staffList[3].skill, "Makeup Artist");
    staffList[3].availability = 0;

    strcpy(staffList[4].name, "Afaf Shahid");
    staffList[4].salary = 5200.0;
    strcpy(staffList[4].skill, "Waxing Special");
    staffList[4].availability = 1;

    return staffList;
}

// Function to free memory allocated for staffList
void freeStaffList(struct Staff* staffList) {
    free(staffList);
}

void displayServices(struct Service* services, int numServices) {
    printf("\n\t\tServices:");
    for (int i = 0; i < numServices; i++) {
        printf("\n\t\t %2d. %-40s $%d", i + 1, services[i].name, services[i].price);
    }
}

void displayStaff(struct Staff* staffList, int numStaff) {
    printf("\n\t\t--------------------- Staff List --------------------");
    for (int i = 0; i < numStaff; i++) {
        printf("\n\t\t%d. %-30s%-15s",
               i + 1,
               staffList[i].name,
               staffList[i].availability ? "Available" : "Not Available");
    }
    printf("\n\t\t------------------------------------------------------");
}

// Function to display staff members in a table with index
void displayStaffTable(struct Staff* staffList, int numStaff) {
    printf("\n\t\t--------------------- Staff List --------------------");
    printf("\n\t\t%-23s%-15s%-15s%-20s", "Name", "Salary", "Skill", "Availability");
    
    for (int i = 0; i < numStaff; i++) {
        printf("\n\t\t%d. %-20s%-15.2f%-15s%-20s",
               i + 1,
               staffList[i].name,
               staffList[i].salary,
               staffList[i].skill,
               staffList[i].availability ? "Available" : "Not Available");
    }
    printf("\n\t\t------------------------------------------------------");
}


// Function to add a new staff member to the staffList
void addStaff(struct Staff** staffList, int* numStaff) {
    // Increase the size of staffList using dynamic memory allocation
    *staffList = (struct Staff*)realloc(*staffList, (*numStaff + 1) * sizeof(struct Staff));

    if (*staffList == NULL) {
        printf("Error reallocating memory for staffList");
        exit(EXIT_FAILURE);
    }

    // Input details for the new staff member
    printf("\nEnter staff name: ");
    scanf(" %[^\n]", (*staffList)[*numStaff].name);

    printf("Enter staff salary: ");
    scanf("%f", &(*staffList)[*numStaff].salary);

	printf("Enter staff skill: ");
	scanf(" %[^\n]", (*staffList)[*numStaff].skill);

	int availability;
	printf("Is staff available? (1 for Yes, 0 for No): ");
	while (1) {
	    if (scanf("%d", &availability) == 1 && (availability == 0 || availability == 1)) {
	        (*staffList)[*numStaff].availability = availability;
	        break;
	    } else {
	        printf("Invalid input. Please enter 0 for No or 1 for Yes: ");
	        while (getchar() != '\n'); // Clear the input buffer
	    }
	}

    // Increment the number of staff members
    (*numStaff)++;

    printf("\nStaff member added successfully!\n");
}

// Function to remove a staff member from the staffList
void removeStaff(struct Staff** staffList, int* numStaff) {
    int staffIndex;
    
    // Display the current staff list
    displayStaffTable(*staffList, *numStaff);

    // Ask for the staff index to be removed
    printf("\nEnter the number corresponding to the staff member to remove: ");
    scanf("%d", &staffIndex);

    // Validate the input index
    if (staffIndex >= 1 && staffIndex <= *numStaff) {
        staffIndex--; // Adjust index to match array indexing

        // Move the staff members after the removed one to fill the gap
        for (int i = staffIndex; i < *numStaff - 1; i++) {
            (*staffList)[i] = (*staffList)[i + 1];
        }

        // Decrease the number of staff members
        (*numStaff)--;

        // Resize the staffList array
        *staffList = (struct Staff*)realloc(*staffList, *numStaff * sizeof(struct Staff));

        if (*staffList == NULL) {
            perror("Error reallocating memory for staffList");
            exit(EXIT_FAILURE);
        }

        printf("\nStaff member removed successfully!\n");
    } else {
        printf("\nInvalid staff number. Please enter a valid staff member number.\n");
    }
}

// Function to edit details of an existing staff member
void editStaff(struct Staff* staffList, int numStaff) {
    int staffIndex;

    // Display the current staff list
    displayStaffTable(staffList, numStaff);

    // Ask for the staff index to be edited
    printf("\nEnter the number corresponding to the staff member to edit: ");
    scanf("%d", &staffIndex);

    // Validate the input index
    if (staffIndex >= 1 && staffIndex <= numStaff) {
        staffIndex--; // Adjust index to match array indexing

        // Display the current details of the selected staff member
        printf("\nCurrent Details for %s:", staffList[staffIndex].name);
        printf("\n1. Name: %s", staffList[staffIndex].name);
        printf("\n2. Salary: %.2f", staffList[staffIndex].salary);
        printf("\n3. Skill: %s", staffList[staffIndex].skill);
        printf("\n4. Availability: %s\n", staffList[staffIndex].availability ? "Available" : "Not Available");

        int choice;
        printf("Enter the number corresponding to the detail to edit (0 to go back): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new name: ");
                scanf(" %[^\n]", staffList[staffIndex].name);
                break;

            case 2:
                printf("Enter the new salary: ");
                scanf("%f", &staffList[staffIndex].salary);
                break;

            case 3:
                printf("Enter the new skill: ");
                scanf(" %[^\n]", staffList[staffIndex].skill);
                break;

            case 4:
                printf("Is the staff member available? (1 for Yes, 0 for No): ");
                while (1) {
                    int availability;
                    if (scanf("%d", &availability) == 1 && (availability == 0 || availability == 1)) {
                        staffList[staffIndex].availability = availability;
                        break;
                    } else {
                        printf("Invalid input. Please enter 0 for No or 1 for Yes: ");
                        while (getchar() != '\n'); // Clear the input buffer
                    }
                }
                break;

            case 0:
                // Go back
                break;

            default:
                printf("Invalid option. No changes made.\n");
                break;
        }
    } else {
        printf("\nInvalid staff number. Please enter a valid staff member number.\n");
    }
}

// Function for staff management
void staffManagement(struct Staff** staffList, int* numStaff) {
    int choice;
    do {
        printf("\nStaff Management Options:\n");
        printf("1. Display Staff\n");
        printf("2. Add Staff\n");
        printf("3. Remove Staff\n");
        printf("4. Edit Staff Member\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display Staff
                displayStaffTable(*staffList, *numStaff);
                break;

            case 2:
                // Add Staff
                addStaff(staffList, numStaff);
                break;

            case 3:
                // Remove Staff
                removeStaff(staffList, numStaff);
                break;

            case 4:
                // Edit Staff Member
                editStaff(*staffList, *numStaff);
                break;

            case 0:
                // Back to Main Menu
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);
}


void displayMembershipOptions() {
    printf("\n\t\tMembership Options:");
    printf("\n\t\t 1. Silver Membership \t\t $50/month");
    printf("\n\t\t 2. Gold Membership \t\t $80/month");
    printf("\n\t\t 3. Platinum Membership \t $120/month");
}

void applyDiscount(float *totalAmount, int membershipType) {
    // Apply discount based on membership type
    switch (membershipType) {
        case 1: // Silver Membership
            *totalAmount *= 0.9; // 10% discount
            break;
        case 2: // Gold Membership
            *totalAmount *= 0.75; // 25% discount
            break;
        case 3: // Platinum Membership
            *totalAmount *= 0.7; // 30% discount
            break;
        default:
            break;
    }
}

int processMembership(char customerName[100]) {
    int membershipType = 0;

    printf("\nDo you already have a membership? (y/n): ");
    char hasMembership;
    scanf(" %c", &hasMembership);

    if (hasMembership == 'y' || hasMembership == 'Y') {
        // Search for the customer's membership type in the preexisting file
        FILE *membershipsFile = fopen("memberships.txt", "r");
        if (membershipsFile == NULL) {
            printf("Error opening file");
            exit(EXIT_FAILURE);
        }

        char line[100];
        int membershipFound = 0;  // Flag to track if the membership is found

        while (fgets(line, sizeof(line), membershipsFile) != NULL) {
            char storedName[100];
            int storedMembershipType;
            sscanf(line, "%s %d", storedName, &storedMembershipType);

            if (strcmp(customerName, storedName) == 0) {
                membershipType = storedMembershipType;
                membershipFound = 1;
                break;
            }
        }

        fclose(membershipsFile);

        if (!membershipFound) {
            printf("\nYou do not have a membership according to our records.\n");
            // Ask if the user wants to purchase a membership
            printf("Would you like to purchase a membership? (y/n): ");
            char purchaseMembership;
            scanf(" %c", &purchaseMembership);

            if (purchaseMembership == 'y' || purchaseMembership == 'Y') {
                displayMembershipOptions();
                printf("\nEnter the number corresponding to your chosen membership: ");
                scanf("%d", &membershipType);

                // Update the memberships file with the user's name and membership type
                FILE *membershipsFile = fopen("memberships.txt", "a");
                if (membershipsFile == NULL) {
                    perror("Error opening file");
                    exit(EXIT_FAILURE);
                }

                fprintf(membershipsFile, "%s %d\n", customerName, membershipType);
                fclose(membershipsFile);

                printf("\nMembership purchased successfully!\n");
            } else {
                // Customer chooses not to purchase a membership
                membershipType = 0;
            }
        }
    } else {
        // Customer doesn't have a membership
        printf("\nWould you like to purchase a membership? (y/n): ");
        char purchaseMembership;
        scanf(" %c", &purchaseMembership);

        if (purchaseMembership == 'y' || purchaseMembership == 'Y') {
            displayMembershipOptions();
            printf("\nEnter the number corresponding to your chosen membership: ");
            scanf("%d", &membershipType);

            // Update the memberships file with the user's name and membership type
            FILE *membershipsFile = fopen("memberships.txt", "a");
            if (membershipsFile == NULL) {
                printf("Error opening file");
                exit(EXIT_FAILURE);
            }

            fprintf(membershipsFile, "%s %d\n", customerName, membershipType);
            fclose(membershipsFile);

            printf("\nMembership purchased successfully!\n");
        } else {
            // Customer chooses not to purchase a membership
            membershipType = 0;
        }
    }

    return membershipType;
}

int isTimeValid(char time[]) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);

    // Check if time is between 9AM and 7PM
    if (hours >= 9 && hours < 19) {
        return 1; // Valid time
    } else {
        return 0; // Invalid time
    }
}

int isDateValid(char date[]) {
    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) == 3) {
        // Check if the year, month, and day are within reasonable ranges
        if (year >= 2023 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            return 1; // Valid date
        }
    }

    return 0; // Invalid date
}

int bookAppointment(struct Staff staffList[], int selectedStaff, const char *appointmentsFileName, float totalAmount) {
    char time[6], date[11];

    int isValidDate = 0, isValidTime = 0;

    while (!isValidDate || !isValidTime) {
        // Get preferred appointment date from the user
        printf("\nEnter preferred appointment date (YYYY-MM-DD): ");
        scanf("%s", date);

        // Validate the date
        isValidDate = isDateValid(date);

        // Get preferred appointment time from the user
        printf("Enter preferred appointment time in 24HR format (HH:MM): ");
        scanf("%s", time);

        // Validate the time
        isValidTime = isTimeValid(time);

        // Check if either date or time is invalid and inform the user
        if (!isValidDate || !isValidTime) {
            printf("\nInvalid date or time. Please choose a valid date and time.\n");
        }
    }

    FILE *appointmentsFile = fopen(appointmentsFileName, "r");
    if (appointmentsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Check if the selected staff, time, and date are available
    int isAvailable = 1;
    char line[100];
    while (fgets(line, sizeof(line), appointmentsFile) != NULL) {
        char storedStaff[100], storedTime[6], storedDate[11];
        sscanf(line, "%s %s %s", storedStaff, storedTime, storedDate);

        if (strcmp(staffList[selectedStaff].name, storedStaff) == 0 && strcmp(time, storedTime) == 0 && strcmp(date, storedDate) == 0) {
            isAvailable = 0; // Appointment time is not available on the specified date
            break;
        }
    }

    fclose(appointmentsFile);

    if (isAvailable) {
        // Book the appointment
        appointmentsFile = fopen(appointmentsFileName, "a");
        if (appointmentsFile == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        fprintf(appointmentsFile, "%s %s %s\n", staffList[selectedStaff].name, time, date);
        fclose(appointmentsFile);

        // Display details of the booked appointment
        printf("\nAppointment booked successfully!\n");
        printf("Details: Staff: %s, Time: %s, Date: %s\n", staffList[selectedStaff].name, time, date);
        printf("Total Amount: $%.2f\n", totalAmount);

        return 1; // Indicate that the appointment was booked
    } else {
        printf("\nAppointment time is not available on the specified date. Please choose another time or date.\n");
        return 0; // Indicate that the appointment was not booked
    }
}

struct Appointment {
    char staffName[100];
    char time[10];
    char date[11];
};

// Function to display appointments
void displayAppointments() {
    
    // Reopen the memberships file for reading
    FILE* appointmentsFile = fopen("appointments.txt", "r");
    if (appointmentsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("\nAppointments:\n");
    rewind(appointmentsFile); // Move file pointer to the beginning

    struct Appointment appointment;

    // Read and display each appointment
    while (fscanf(appointmentsFile, " %99[^\n]%*c", appointment.staffName) == 1) {
        printf("%s\n", appointment.staffName);
    }
	fclose(appointmentsFile);
}

// Function to add an appointment
void addAppointment(const char *appointmentsFileName) {
    struct Appointment newAppointment;

    printf("\nEnter staff name: ");
    scanf(" %[^\n]", newAppointment.staffName);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", newAppointment.time);

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);

    FILE *appointmentsFile = fopen(appointmentsFileName, "a");
    if (appointmentsFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(appointmentsFile, "\n%s %s %s\n", newAppointment.staffName, newAppointment.time, newAppointment.date);

    fclose(appointmentsFile);

    printf("\nAppointment added successfully!\n");
}

// Function to remove an appointment
void removeAppointment() {
    FILE* appointmentsFile = fopen("appointments.txt", "r");
    if (appointmentsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    printf("\nAppointments:\n");

    // Display all appointments with indices
    rewind(appointmentsFile);
    struct Appointment appointment;
    int index = 1;

    while (fscanf(appointmentsFile, " %[^\n]", appointment.staffName) == 1) {
        printf("%d. %s\n", index, appointment.staffName);
        index++;
    }

    // Prompt admin to enter the index to remove
    int appointmentIndex;
    printf("\nEnter the index of the appointment to remove: ");
    scanf("%d", &appointmentIndex);

    // Create a temporary file to store appointments
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file");
        exit(EXIT_FAILURE);
    }

    // Copy all appointments except the one to be removed to the temporary file
    rewind(appointmentsFile);
    index = 1;

    while (fscanf(appointmentsFile, " %[^\n]", appointment.staffName) == 1) {
        if (index == appointmentIndex) {
            // Skip the appointment to be removed
            index++;
            continue;
        }
        fprintf(tempFile, "%s\n", appointment.staffName);
        index++;
    }

    // Close both files
    fclose(appointmentsFile);
    fclose(tempFile);

    // Remove the original file
    if (remove("appointments.txt")) 
    {
		printf("Error removing file");
		exit(EXIT_FAILURE);
    }

    // Rename the temporary file to the original file
    if (rename("temp.txt", "appointments.txt") != 0) {
        perror("Error renaming file");
        exit(EXIT_FAILURE);
    }

    printf("\nAppointment removed successfully!\n");
}

// Function for appointment management
void appointmentManagement() {
    int choice;

    do {
        printf("\nAppointment Management Options:\n");
        printf("1. Display Appointments\n");
        printf("2. Add Appointment\n");
        printf("3. Remove Appointment\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display Appointments
                displayAppointments();
                break;

            case 2:
                // Add Appointment
                addAppointment("appointments.txt");
                break;

            case 3:
                // Remove Appointment
                removeAppointment();
                break;

            case 0:
                // Back to Main Menu
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);
}




int selectServices(struct Service services[], int chosenServices[], int numServices, float *totalAmount) {
    int service;
    char addMoreServices;

    do {
        printf("\n\t----------------------------Choose a Service----------------------------");
        displayServices(services, numServices);

        printf("\nEnter Service Number: ");
        scanf("%d", &service);

        if (service >= 1 && service <= numServices) {
            // Add service to cart
            chosenServices[service - 1] = 1;
            *totalAmount += services[service - 1].price; // Update total amount
            printf("\n\t\tService '%s' added to your cart.", services[service - 1].name);

            // Ask if the customer wants to add more services
            printf("\n\tDo you want to add more services? (y/n): ");
            scanf(" %c", &addMoreServices);
        } else {
            printf("\n\tInvalid service number. Please choose a valid service.\n");
            addMoreServices = 'y'; // To continue the loop
        }

    } while (addMoreServices == 'y' || addMoreServices == 'Y');

    return 1; // Indicate that services were selected
}

// Function to manage services
void serviceManagement(struct Service** services, int* numServices) {
    int choice;
    do {
        printf("\nService Management Options:\n");
        printf("1. Display Services\n");
        printf("2. Add Service\n");
        printf("3. Remove Service\n");
        printf("4. Edit Service\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display Services
                displayServices(*services, *numServices);
                break;

            case 2:
                // Add Service
                *services = (struct Service*)realloc(*services, (*numServices + 1) * sizeof(struct Service));

                if (*services == NULL) {
                    perror("Error reallocating memory for services");
                    exit(EXIT_FAILURE);
                }

                printf("\nEnter service name: ");
                scanf(" %[^\n]", (*services)[*numServices].name);

                printf("Enter service price: ");
                scanf("%d", &(*services)[*numServices].price);

                (*numServices)++;

                printf("\nService added successfully!\n");
                break;

            case 3:
                // Remove Service
                int serviceIndex;
                displayServices(*services, *numServices);
                printf("\nEnter the number corresponding to the service to remove: ");
                scanf("%d", &serviceIndex);

                if (serviceIndex >= 1 && serviceIndex <= *numServices) {
                    serviceIndex--; // Adjust index to match array indexing

                    for (int i = serviceIndex; i < *numServices - 1; i++) {
                        (*services)[i] = (*services)[i + 1];
                    }

                    (*numServices)--;

                    *services = (struct Service*)realloc(*services, *numServices * sizeof(struct Service));

                    if (*services == NULL) {
                        perror("Error reallocating memory for services");
                        exit(EXIT_FAILURE);
                    }

                    printf("\nService removed successfully!\n");
                } else {
                    printf("\nInvalid service number. Please enter a valid service number.\n");
                }
                break;

            case 4:
                // Edit Service
                int serviceIndexEdit;
                displayServices(*services, *numServices);
                printf("\nEnter the number corresponding to the service to edit: ");
                scanf("%d", &serviceIndexEdit);

                if (serviceIndexEdit >= 1 && serviceIndexEdit <= *numServices) {
                    serviceIndexEdit--; // Adjust index to match array indexing

                    printf("\nEnter the new name for the service: ");
                    scanf(" %[^\n]", (*services)[serviceIndexEdit].name);

                    printf("Enter the new price for the service: ");
                    scanf("%d", &(*services)[serviceIndexEdit].price);

                    printf("\nService edited successfully!\n");
                } else {
                    printf("\nInvalid service number. Please enter a valid service number.\n");
                }
                break;

            case 0:
                // Back to Main Menu
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

struct Membership {
    char name[100];
    int type;
};

void displayMembershipsRecursive(FILE *membershipsFile) {
    char line[256];  // Adjust the size accordingly based on your data

    if (fgets(line, sizeof(line), membershipsFile) != NULL) {
        // Print the current line
        printf("%s", line);

        // Recursively call the function for the next line
        displayMembershipsRecursive(membershipsFile);
    } else {
        // Base case: end of file reached
        return;
    }
}

// Wrapper function for starting recursion
void displayMemberships(FILE *membershipsFile) {
    rewind(membershipsFile);
    printf("\nMemberships:\n");

    // Start recursion
    displayMembershipsRecursive(membershipsFile);
}

void addMembership(FILE *membershipsFile) {
    struct Membership newMembership;

    printf("\nEnter member name: ");
    scanf(" %[^\n]", newMembership.name);

    printf("Enter member type (1 for Silver, 2 for Gold, 3 for Platinum): ");
    scanf("%d", &newMembership.type);

    // Open the file in append mode
    membershipsFile = fopen("memberships.txt", "a");
    if (membershipsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the new membership to the file
    fprintf(membershipsFile, "%s %d\n", newMembership.name, newMembership.type);

    // Close the file
    fclose(membershipsFile);

    // Open the file for reading
    membershipsFile = fopen("memberships.txt", "r");
    if (membershipsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }
}

void removeMembership(FILE *membershipsFile) {
    fclose(membershipsFile);  // Close the file before reopening

    // Reopen the file in read mode
    membershipsFile = fopen("memberships.txt", "r");
    if (membershipsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct Membership membership;
    int index = 1;

    printf("\nMemberships:\n");

    // Display all memberships with indices
    while (fscanf(membershipsFile, "%s %d", membership.name, &membership.type) == 2) {
        printf("%d. %s %d\n", index, membership.name, membership.type);
        index++;
    }

    // Prompt admin to enter the index to remove
    int membershipIndex;
    printf("\nEnter the index of the membership to remove: ");
    scanf("%d", &membershipIndex);

    // Create a temporary file to store memberships
    FILE *tempFile = fopen("temp_memberships.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file");
        exit(EXIT_FAILURE);
    }

    // Copy all memberships except the one to be removed to the temporary file
    rewind(membershipsFile);
    index = 1;

    while (fscanf(membershipsFile, "%s %d", membership.name, &membership.type) == 2) {
        if (index == membershipIndex) {
            // Skip the membership to be removed
            index++;
            continue;
        }
        fprintf(tempFile, "%s %d\n", membership.name, membership.type);
        index++;
    }

    // Close both files
    fclose(membershipsFile);
    fclose(tempFile);

    // Remove the original file
    if (remove("memberships.txt") != 0) {
        printf("Error removing original file");
        exit(EXIT_FAILURE);
    }

    // Rename the temporary file to the original file
    if (rename("temp_memberships.txt", "memberships.txt") != 0) {
        printf("Error renaming file");
        exit(EXIT_FAILURE);
    }

    // Reopen the memberships file for reading
    membershipsFile = fopen("memberships.txt", "r");
    if (membershipsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("\nMembership removed successfully!\n");
}



void membershipManagement(FILE *membershipsFile) {
    int choice;

    do {
        printf("\nMembership Management Options:\n");
        printf("1. Display Memberships\n");
        printf("2. Add Membership\n");
        printf("3. Remove Membership\n");
        printf("0. Back to Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display Memberships
                displayMemberships(membershipsFile);
                break;

            case 2:
                // Add Membership
                addMembership(membershipsFile);
                break;

            case 3:
                // Remove Membership
                removeMembership(membershipsFile);
                break;

            case 0:
                // Back to Admin Menu
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

void displayCart(struct Service services[], int chosenServices[], int numServices, float *totalAmount, int membershipType) {
    printf("\n\t\t---------------------- Your Shopping Cart ----------------------");

    // Display selected services
    printf("\n\t\tSelected Services:");
    for (int i = 0; i < numServices; i++) {
        if (chosenServices[i] == 1) {
            printf("\n\t\t %2d. %-40s $%d", i + 1, services[i].name, services[i].price);
        }
    }

    // Display membership discount, if any
    if (membershipType != 0) {
        float discountAmount = 0.0;

        // Calculate discount amount based on membership type
        switch (membershipType) {
            case 1:
                discountAmount = 0.1 * (*totalAmount); // Silver Membership (10%)
                break;
            case 2:
                discountAmount = 0.25 * (*totalAmount); // Gold Membership (25%)
                break;
            case 3:
                discountAmount = 0.3 * (*totalAmount); // Platinum Membership (30%)
                break;
            default:
                break;
        }

        printf("\n\t\tMembership Discount Applied: $%.2f\n", discountAmount);
    } else {
        printf("\n\t\tNo Membership Discount Applied\n");
    }

    // Display total amount
    printf("\n\t\tTotal Amount: $%.2f\n", *totalAmount);

    // Loop to repeatedly ask if the user wants to remove a service
    char removeOption;
    do {
        printf("\n\t\tDo you want to remove a service? (y/n): ");
        scanf(" %c", &removeOption);

        if (removeOption == 'y' || removeOption == 'Y') {
            int serviceIndex;
            printf("\n\t\tEnter the index of the service to remove: ");
            scanf("%d", &serviceIndex);

            if (serviceIndex >= 1 && serviceIndex <= numServices && chosenServices[serviceIndex - 1] == 1) {
                chosenServices[serviceIndex - 1] = 0; // Remove the service from the cart
                *totalAmount -= services[serviceIndex - 1].price; // Update totalAmount
                printf("\n\t\tService '%s' removed from the cart.\n", services[serviceIndex - 1].name);
            } else {
                printf("\n\t\tInvalid index or service not selected. No service removed.\n");
            }
        } else if (removeOption != 'n' && removeOption != 'N') {
            printf("\n\t\tInvalid option. Please enter 'y' or 'n'.\n");
        }
    } while (removeOption == 'y' || removeOption == 'Y');

    printf("\n\t\t------------------------------------------------------------------");
}

int main() {
    int CorA, customerOption, adminOption, staff;
    int numStaff = 5;
    int numServices = 14;
    int chosenServices[14] = {0}; // Array to store chosen services
    int serviceSelected = 0; // Flag to track if services have been selected
    int staffSelected = 0;   // Flag to track if staff has been selected
    int membershipType = 0;  // 0: No membership, 1: Silver, 2: Gold, 3: Platinum
    float totalAmount = 0.0; // Total amount of selected services
    int appointmentBooked = 0; // Flag to track if an appointment has been booked
    // Initialize services and staffList using DMA
    struct Service* services = initializeServices();
    struct Staff* staffList = initializeStaffList();


    // Open memberships file in read mode
    FILE *membershipsFile = fopen("memberships.txt", "r");
    if (membershipsFile == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }


	do{
    printf("\nLogin for: \n1. Customer \n2. Admin \n0. Exit \nEnter Number: ");
    scanf("%d", &CorA);

    switch (CorA) {
        case 1:
            printf("\n\t--------------------Welcome to SalonPro: Streamlining Beauty Services!--------------------");

            // Customer module switch case
            do {
                printf("\nCustomer Options: \n1. Service Selection \n2. Staff Selection \n3. Cart Management \n4. Membership \n5. Book Appointment \n0. Exit \nEnter Option: ");
                scanf("%d", &customerOption);

                switch (customerOption) {
                    case 1:
                        // Service Selection
                        selectServices(services, chosenServices, 14, &totalAmount);
                        serviceSelected = 1; // Flag that services have been selected
                        break;

                    case 2:
					    // Staff Selection
					    if (serviceSelected) {
					        int validSelection = 0;
					
					        do {
					            displayStaff(staffList, 5);
					            printf("\nEnter Staff Number: ");
					            scanf("%d", &staff);
					
					            if (staff >= 1 && staff <= 5 && staffList[staff - 1].availability) {
					                staff--; // Adjust index to match array indexing
					                staffSelected = 1;
					                validSelection = 1;
					            } else {
					                if (staff < 1 || staff > 5) {
					                    printf("\nInvalid staff number. Please choose a valid staff member.\n");
					                } else if (!staffList[staff - 1].availability) {
					                    printf("\nSelected staff (%s) is not available. Please choose an available staff member.\n", staffList[staff - 1].name);
					                }
					            }
					        } while (!validSelection);
					    } else {
					        printf("\nPlease select services before choosing a staff member.\n");
					    }
					    break;
					
					case 3:
					    // Cart Management
					    if (serviceSelected) {
					        // Display cart after services have been selected
					        displayCart(services, chosenServices, 14, &totalAmount, membershipType);
					    } else {
					        printf("\nPlease select services before viewing the cart.\n");
					    }
					    break;
					    
                    case 4:
                        // Membership
                        if (serviceSelected && staffSelected) { // Check if a service and staff have been selected
                            printf("\nEnter your name: ");
                            char customerName[100];
                            scanf("%s", customerName);

                            membershipType = processMembership(customerName);

                            // Apply discount based on membership type
                            applyDiscount(&totalAmount, membershipType);

                            printf("\nMembership discount applied.\n");

                        } else {
                            printf("\nPlease select a service and staff before applying for membership.\n");
                        }
                        break;

                    case 5:
                        // Book Appointment
                        if (serviceSelected && staffSelected) { // Check if a service and staff have been selected
                            if (!appointmentBooked) {
                                appointmentBooked = bookAppointment(staffList, staff, "appointments.txt", totalAmount);
                                serviceSelected = 0; // Reset the flags for the next session
                                staffSelected = 0;
                                membershipType = 0; // Reset membership type
                                chosenServices[14] = {0};
                                appointmentBooked = 0;
                            } 
                        } else {
                            printf("\nPlease select a service and staff before booking an appointment.\n");
                        }
                        break;
					
					case 0: 
						break;
					
                    default:
                        printf("Invalid option. Please try again.\n");
                }
            } while (customerOption != 0);
            break;

        case 2:
            // Admin module 
            // Admin authentication
            char adminUsername[20];
            char adminPassword[20]; 

            do {
                printf("\nEnter Admin Username: ");
                scanf("%s", adminUsername);

                printf("Enter Admin Password: ");
                scanf("%s", adminPassword);

                if (strcmp(adminUsername, "admin") == 0 && strcmp(adminPassword, "Salon1234") == 0) {
                    printf("\nAuthentication successful. Welcome, Admin!\n");
                } else {
                    printf("\nAuthentication failed. Please try again.\n");
                }

            } while (strcmp(adminUsername, "admin") != 0 || strcmp(adminPassword, "Salon1234") != 0 );
			
			do{
			    printf("\nAdmin Options: \n1. Staff Management \n2. Service Management \n3. Appointment Management \n4. Membership Management \n0. Exit \nEnter Option: ");
			    scanf("%d", &adminOption);
			
			    switch (adminOption) {
			        case 1:
			            // Staff Management
			            staffManagement(&staffList, &numStaff);
			            break;
			
			        case 2:
			            // Service Management
			            serviceManagement(&services, &numServices);
			            break;
			
			        case 3:
			            // Appointment Management
			            appointmentManagement();
			            break;
			
			        case 4:
			            // Membership Management
			            membershipManagement(membershipsFile);;
			            break;
			            
			        case 0:
			        	break;
			
			        default:
			            printf("Invalid option. Please try again.\n");
			            break;
			    }
			} while(adminOption!=0);
		} 
	}while(CorA!=0);
	freeServices(services);
    freeStaffList(staffList);
}

