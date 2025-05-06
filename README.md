# SalonPro: Salon Management System

## Overview

SalonPro is a comprehensive C-based management system designed for beauty salons and spas. It streamlines the process of managing services, staff, memberships, and appointments, providing an efficient solution for both customers and administrators.

## Features

### For Customers:
- **Service Selection**: Browse and select from a variety of beauty services
- **Staff Selection**: Choose from available staff members
- **Cart Management**: View and modify selected services
- **Membership Management**: Purchase memberships with tiered discount benefits
  - Silver (10% discount)
  - Gold (25% discount)
  - Platinum (30% discount)
- **Appointment Booking**: Schedule appointments with preferred staff members

### For Administrators:
- **Staff Management**: Add, remove, edit, and view staff details
- **Service Management**: Add, remove, edit, and view salon services
- **Appointment Management**: View, add, and remove appointments
- **Membership Management**: View, add, and remove customer memberships

## Installation

### Prerequisites
- C compiler (GCC recommended)
- Standard C libraries

### Compilation
To compile the SalonPro program:

```bash
gcc -o salonpro runesayfinal.cpp
```

### Running the Program
After compilation, run the program:

```bash
./salonpro
```

## Usage Guide

### Initial Login Screen
When you start the program, you'll be presented with a login screen:
```
Login for:
1. Customer
2. Admin
0. Exit
Enter Number:
```

### Customer Module

#### 1. Service Selection
- Browse available services with prices
- Select services to add to your cart
- Multiple services can be added

#### 2. Staff Selection
- View available staff members
- Select a preferred staff member for your appointment
- Only available staff members can be selected

#### 3. Cart Management
- View selected services
- Remove services from your cart
- View total amount
- Check membership discount (if applicable)

#### 4. Membership
- Check for existing membership
- Purchase a new membership (Silver, Gold, or Platinum)
- Apply membership discount to total amount

#### 5. Book Appointment
- Choose preferred date and time
- Confirm appointment details
- Receive appointment confirmation

### Admin Module

#### 1. Staff Management
- Display all staff members with details
- Add new staff members
- Remove existing staff members
- Edit staff information (name, salary, skill, availability)

#### 2. Service Management
- Display all services with prices
- Add new services
- Remove existing services
- Edit service information (name, price)

#### 3. Appointment Management
- Display all booked appointments
- Add new appointments manually
- Remove existing appointments

#### 4. Membership Management
- Display all customer memberships
- Add new memberships manually
- Remove existing memberships

## File Structure

The system uses the following files:
- `memberships.txt`: Stores customer membership data
- `appointments.txt`: Stores appointment bookings

## Admin Authentication

To access the admin module:

1. Select option 2 (Admin) from the main login screen
2. You will be prompted for authentication:
   ```
   Enter Admin Username: admin
   Enter Admin Password: Salon1234
   ```
3. After successful authentication, you'll gain access to the admin dashboard
4. The system will present admin management options

**Security Note**: The admin credentials are hardcoded in the system for demonstration purposes. In a production environment, it's recommended to implement more secure authentication methods.

## Notes

- The salon's operating hours are from 9:00 AM to 7:00 PM
- Appointments can only be booked during operating hours
- Membership discounts are automatically applied when booking
- Staff availability is checked before confirming appointments

## Troubleshooting

If you encounter errors:
- Ensure all required files exist in the same directory
- Check file permissions
- Verify admin credentials
- Ensure date and time formats match the required format (YYYY-MM-DD and HH:MM)
