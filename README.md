# UiTM Arau Laundry Pickup Service

A C++ console program for booking laundry and dry-cleaning pickups at UiTM Arau's residential colleges. It calculates the price from the weight and temperature chosen and prints a receipt.

Group project for CSC126 (Fundamentals of Algorithms & Computer Problem Solving), Diploma in Computer Science, UiTM Perlis. February 2023.

## Background

Students at Dahlia, Cengal and Kesinai had to send their laundry to shops outside campus, which were far away and not cheap. We proposed a pickup service for the college's student council (Jawatan Perwakilan Kolej) where students order through this program and get a receipt as proof of payment.

## Demo

[![Watch the demo](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://youtu.be/_edde9KxzAg?si=2a-3-BCmJP0L5vbz)

## How it works

1. The student logs in with their student ID and password.
2. They pick their college, the service (laundry, dry-cleaning or both), the laundry weight and the temperature.
3. The program adds up the weight price and the temperature price, then prints a receipt.

## Pricing

| Weight | Price |
|---|---|
| 5 kg | RM3.00 |
| 10 kg | RM3.50 |
| 15 kg | RM4.00 |
| 20 kg | RM4.50 |
| 25 kg | RM5.00 |
| 30 kg | RM5.50 |

| Code | Laundry | Dry-cleaning | Price |
|---|---|---|---|
| A | Cold | Low | RM4.00 |
| B | Warm | Medium | RM5.00 |
| C | Hot | High | RM6.00 |

If both services are chosen, both temperature prices are added.

## Running it

```bash
g++ -std=c++14 source_code.cpp -o laundry
./laundry
```

Demo login: `1234567890` / `demo123`

## Files

- `source_code.cpp` – the program
- `docs/` – project report (pseudocode, flowcharts, sample output) and presentation slides

## My part

<!-- e.g. I wrote the login system and the pricing functions, and drew the flowcharts. -->

## What I'd change now

This was my first programming project. If I rewrote it, I would stop hardcoding the login details, reject invalid input like a 12 kg weight or an unknown college code, and save orders to a file.
