# 🏅 Sports Club Management System
### Object-Oriented Programming — Semester Project

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/Paradigm-OOP-blueviolet?style=for-the-badge)
![Classes](https://img.shields.io/badge/Classes-5-green?style=for-the-badge)
![Roles](https://img.shields.io/badge/Roles-3%20(User%2FInstructor%2FAdmin)-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

</div>

## 📋 Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Class Diagram](#class-diagram)
4. [Class Reference](#class-reference)
   - [String](#-string-class)
   - [registration](#-registration-class)
   - [membership](#-membership-class)
   - [User](#-user-class)
   - [menu](#-menu-class)
5. [OOP Concepts Used](#oop-concepts-used)
6. [System Workflow](#system-workflow)
7. [User Manual](#user-manual)
8. [Membership & Fees Logic](#membership--fees-logic)
9. [Setup & Compilation](#setup--compilation)
10. [Project Structure](#project-structure)
11. [Authors](#authors)

---

## Overview

The **Ironclads Sports Club Management System** is a console-based C++ application that provides a complete environment for managing sports club operations. It supports three distinct roles — **User**, **Instructor**, and **Admin** — each with their own login portal and dedicated set of operations.

Users can register with personal details and sports preferences, instructors can view their assigned schedules, and administrators can manage all registrations and instructor data from a centralized admin panel.

The project demonstrates core **Object-Oriented Programming** principles including **encapsulation**, **composition**, **abstraction**, and **method overloading** through a clean, modular five-class design.

---

## Features

### 👤 User
- Register with full personal details (name, age, gender, CNIC, nationality, address, contact)
- Select preferred sport during registration
- Auto-assignment of instructor, fees, and session timings based on age and gender
- Login with username and password to view full membership profile

### 🧑‍🏫 Instructor
- Dedicated login portal with separate credentials
- View assigned sports, session timings, and registered member details
- Credentials managed by the administrator

### 🛡️ Admin
- Secure admin panel with protected credentials
- View and manage all registered users
- Add, update, or remove instructor information
- Delete member records
- Full oversight of all club operations

### 🏋️ Membership Management
- Dynamic fee calculation based on age group and selected sport
- Automatic instructor assignment per sport and gender
- Time-slot management per sports session

---

## Class Diagram

The diagram below illustrates all 5 classes and their relationships (composition).

![Class Diagram](class_diagram.png)

> *Figure 1: UML Class Diagram — Ironclads Sports Club Management System*

---

## Class Reference

### 🔷 `String` Class

The `String` class stores all **personal details** of a club member. It acts as a pure data container with full getter/setter encapsulation over dynamically allocated `char*` fields.

**Attributes:**

| Attribute     | Type     | Description            |
|---------------|----------|------------------------|
| `firstname`   | `char*`  | Member's first name    |
| `secondname`  | `char*`  | Member's second name   |
| `fathername`  | `char*`  | Father's name          |
| `occupation`  | `char*`  | Occupation             |
| `gender`      | `char*`  | Gender                 |
| `age`         | `int`    | Age                    |
| `CNIC`        | `string` | National ID number     |
| `number`      | `string` | Contact number         |
| `nationality` | `char*`  | Nationality            |
| `address`     | `char*`  | Residential address    |

**Key Methods:**

```cpp
// Setters
void setfirstname(firstname: string);
void setsecondname(secondname: string);
void setfathername(fathername: string);
void setoccupation(occupation: string);
void setnationality(nationality: string);
void setgender(gender: string);
void setage(age: int);
void setcnic(cnic: string);
void setnumber(number: string);
void setaddress(address: string);

// Getters
const char* getfirstname();
const char* getsecondname();
const char* getfathername();
const char* getoccupation();
const char* getnationality();
const char* getgender();
int         getage();
string      getcnic();
string      getnumber();
const char* getaddress();
```

---

### 🔷 `registration` Class

The `registration` class handles **authentication credentials** for each user account.

**Attributes:**

| Attribute  | Type     | Description           |
|------------|----------|-----------------------|
| `password` | `string` | User's login password |
| `username` | `string` | User's login username |

**Key Methods:**

```cpp
void   setPassword(p: string);
void   setUsername(u: string);
string getPassword();
string getUsername();
```

---

### 🔷 `membership` Class

The `membership` class stores **sports membership details** including the selected game, assigned instructor, fee amount, and session time slot.

**Attributes:**

| Attribute       | Type     | Description                        |
|-----------------|----------|------------------------------------|
| `game`          | `char*`  | Selected sport / game              |
| `instructor`    | `char*`  | Assigned instructor name           |
| `amount`        | `double` | Membership fee (PKR)               |
| `time`          | `string` | Session time slot                  |
| `instructorset` | `int`    | Instructor assignment status flag  |

**Key Methods:**

```cpp
void        setGame(newGame: string&);
void        setinstructorset(i: int);           // Single-arg overload
void        setinstructorset(i: int, j: int);   // Two-arg overload
void        setamount(a: double);
void        settime(time: string);
void        setInstructor(newInstructor: string&);

string      gettime();
int         getinstructorset();
const char* getGame();
const char* getInstructor();
double      getAmount();
```

---

### 🔷 `User` Class

The `User` class is the **central entity** of the system. It composes `String`, `registration`, and `membership` together into a single complete user object using the **has-a (composition)** relationship.

**Attributes:**

| Attribute | Type           | Description                        |
|-----------|----------------|------------------------------------|
| `details` | `String`       | Composed personal info object      |
| `reg`     | `registration` | Composed login credentials object  |
| `member`  | `membership`   | Composed membership info object    |

**Key Methods:**

```cpp
void setmembership();
// Assigns instructor, fees, and time slot based on
// the user's selected game, age, and gender.
```

> **Design Note:** `User` demonstrates **composition over inheritance** — it owns fully formed instances of the three supporting classes rather than extending them via inheritance chains.

---

### 🔷 `menu` Class

The `menu` class is the **application controller and entry point**. It drives the main menu loop and delegates all flows to their respective role-based portals.

**Key Methods:**

```cpp
void REGISTRATIONSINGLE();   // Handles full new-user registration flow
void USERLOGIN();            // Authenticates user and displays profile
void INSTRUCTORLOGIN();      // Authenticates instructor and shows schedule
void ADMIN();                // Opens admin panel with management options
```

---

## OOP Concepts Used

| Concept | Where Applied |
|---------|---------------|
| **Encapsulation** | All attributes in `String`, `registration`, and `membership` are `private` with public getters/setters |
| **Composition (Has-A)** | `User` owns objects of `String`, `registration`, and `membership` |
| **Abstraction** | Fee calculation and instructor assignment logic is hidden inside `setmembership()` |
| **Method Overloading** | `setinstructorset(int)` and `setinstructorset(int, int)` are two overloaded variants |
| **Dynamic Memory** | `char*` attributes in `String` and `membership` use heap allocation |
| **Modularity / SRP** | Each class has a single, well-defined responsibility |
| **Controller Pattern** | `menu` class acts as the sole entry point and orchestrator for all user flows |

---

## System Workflow

```
                     ┌──────────────────────┐
                     │      Main Menu       │
                     │    (menu class)      │
                     └──────────┬───────────┘
          ┌───────────┬─────────┴──────────┬───────────┐
          ▼           ▼                    ▼           ▼
  ┌──────────────┐ ┌──────────────┐ ┌───────────────┐ ┌─────────────┐
  │     User     │ │     User     │ │  Instructor   │ │    Admin    │
  │ Registration │ │    Login     │ │    Login      │ │    Panel    │
  │              │ │              │ │               │ │             │
  │ Enter details│ │ Username +   │ │ Username +    │ │ View users  │
  │ Select sport │ │ Password     │ │ Password      │ │ Edit inst.  │
  │              │ │              │ │               │ │ Delete mbr  │
  │ Auto-assign: │ │ View full    │ │ View schedule │ │ Manage cred │
  │  instructor  │ │ profile &    │ │ & members     │ └─────────────┘
  │  fee & time  │ │ membership   │ └───────────────┘
  └──────────────┘ └──────────────┘
```

---

## User Manual

### 📝 User Registration

1. Launch the program — the main menu appears.
2. Select **`1` → User Registration**.
3. Enter personal details when prompted:
   - First name, second name, father's name
   - Age, gender, occupation, nationality
   - CNIC, contact number, residential address
4. Select your preferred sport from the displayed list.
5. The system automatically assigns an **instructor**, **fee**, and **time slot** based on your profile.
6. A **username** and **password** are created — save these for future logins.

---

### 🔐 User Login

1. Select **`2` → User Login** from the main menu.
2. Enter your **username** and **password**.
3. On successful authentication, your full profile is displayed:
   - Personal details
   - Assigned sport and instructor
   - Session time slot and membership fee

---

### 🧑‍🏫 Instructor Login

1. Select **`3` → Instructor Login** from the main menu.
2. Enter your instructor **username** and **password**.
3. On successful login, view:
   - Your assigned sport(s)
   - Session timings
   - List of members registered under your supervision

---

### 🛡️ Admin Panel

1. Select **`4` → Admin Login** from the main menu.
2. Enter the **admin credentials**.
3. Available admin operations:
   - **View all registered users** and their membership details
   - **Add / update instructor** information and login credentials
   - **Delete a member** from the system
   - **Modify instructor login** username or password

---

## Membership & Fees Logic

Membership fees are dynamically calculated inside `User::setmembership()` based on the member's **age group**, **gender**, and **selected sport**.

### Age-Based Fee Tiers

| Age Group    | Category  | Description                          |
|--------------|-----------|--------------------------------------|
| Under 15     | Junior    | Discounted junior membership rate    |
| 15 – 30      | Adult     | Standard adult membership rate       |
| 30+          | Senior    | Senior / professional membership rate|

### Instructor Assignment Logic

- Instructors are assigned per **sport** and **gender** to ensure appropriate pairings.
- The `instructorset` flag in `membership` tracks whether an instructor has already been assigned.
- The overloaded `setinstructorset(i, j)` handles edge cases where two parameters are needed for assignment.

### Sports Offered

| Sport          | Icon |
|----------------|------|
| Cricket        | 🏏   |
| Football       | ⚽   |
| Badminton      | 🏸   |
| Swimming       | 🏊   |
| Boxing / MMA   | 🥊   |

---

## Setup & Compilation

### Prerequisites

- A C++ compiler supporting **C++11** or higher (`g++`, `clang++`, or MSVC)
- Windows / Linux / macOS terminal or IDE (Code::Blocks, VS Code, Dev-C++)

### Compile & Run (Linux / macOS)

```bash
# Clone the repository
git clone https://github.com/your-username/ironclads-sports-club.git
cd ironclads-sports-club

# Compile
g++ -o sports_club main.cpp -std=c++11

# Run
./sports_club
```

### Compile & Run (Windows — MinGW)

```cmd
g++ -o sports_club.exe main.cpp -std=c++11
sports_club.exe
```

### Compile & Run (Multiple Source Files)

```bash
g++ -o sports_club main.cpp String.cpp User.cpp menu.cpp -std=c++11
./sports_club
```

---

## Project Structure

```
sports-club/
│
├── main.cpp                        # Entry point — creates menu object, starts program
│
├── String.h / String.cpp           # Personal details class (firstname, age, CNIC, etc.)
├── registration.h / registration.cpp  # Credentials class (username, password)
├── membership.h / membership.cpp   # Membership class (game, instructor, fee, time)
├── User.h / User.cpp               # Central user entity — composes all three above
├── menu.h / menu.cpp               # Application controller — all login & registration flows
│
├── class_diagram.png               # UML Class Diagram
├── README.md                       # Project documentation (this file)
└── Oop_project_documentation.docx # Original project report
```

---

 
  
> **Course:** Object Oriented Programming (OOP) — Semester Project

---

<div align="center">

**Sports Club Management System** · OOP Semester Project · 2024

</div>
