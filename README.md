# UiTM Arau Laundry Pickup Service

A C++ console app that lets students in UiTM Arau's residential colleges book a laundry and dry-cleaning pickup, then calculates the price and prints a receipt.

**Course:** CSC126 – Fundamentals of Algorithms & Computer Problem Solving
**Programme:** Diploma in Computer Science, UiTM Perlis (Arau)
**Type:** Group project (4 members) · February 2023

---

## The Problem
Students at the Dahlia, Cengal and Kesinai colleges had to take their laundry to shops far off campus that weren't priced for students. This system, proposed for the college's student council (Jawatan Perwakilan Kolej), lets them order a pickup and get a clear receipt as proof of payment.

## Features
- 🔐 **Student login** checks that the ID is numeric and matches the stored credentials
- 🏠 **College selection**: Dahlia, Cengal or Kesinai
- 🧺 **Three service types**: laundry only, dry-cleaning only, or both
- ⚖️ **Weight-based pricing**: 5–30 kg, in 5 kg bags
- 🌡️ **Temperature options**: cold/warm/hot for laundry, low/medium/high for dry-cleaning
- 🧾 **Receipt** showing student ID, college, service type and total payment

## Pricing
| Weight | Price | | Temperature code | Laundry | Dry-cleaning | Price |
|---|---|---|---|---|---|---|
| 5 kg | RM3.00 | | A | Cold | Low | RM4.00 |
| 10 kg | RM3.50 | | B | Warm | Medium | RM5.00 |
| 15 kg | RM4.00 | | C | Hot | High | RM6.00 |
| 20 kg | RM4.50 | | | | | |
| 25 kg | RM5.00 | | | | | |
| 30 kg | RM5.50 | | | | | |

**Total = weight price + temperature price** (both temperature prices are added when you choose laundry *and* dry-cleaning)

## Demo
<!-- Upload the video to YouTube as Unlisted and paste the link, or drag a short clip (<10 MB) into this README on GitHub -->
▶️ [Watch the demo](<!-- video link -->)

<!-- Add a screenshot of the receipt: docs/receipt.png -->

## Concepts Used
Functions and prototypes · arrays · `switch` / `if-else` selection · `while` loops · input validation with `isdigit` · formatted output with `iomanip`

## How to Run
```bash
g++ -std=c++14 source_code.cpp -o laundry
./laundry
```
Demo login: `1234567890` / `demo123` (or `1111111111` / `demo456`)

## Repository Contents
```
source_code.cpp   # full program
docs/             # report (pseudocode, flowchart, sample output), slides
```

## Team
| Member | Role |
|---|---|
| **Nur Hamizah Amnani (Mija)** | <!-- your part, e.g. login system & pricing functions --> |
| Nik Nabila Sofia | <!-- --> |
| Syazmera Zurihan | <!-- --> |
| Natasha Farhana Ibram | <!-- --> |

## Reflection
This was my first programming project. Looking back, I'd improve it by:
- Storing credentials securely instead of hardcoding them
- Rejecting invalid inputs, such as weights that aren't multiples of 5 or unknown college codes
- Saving orders to a file so they persist between runs
