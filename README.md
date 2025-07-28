# Catalog Placements Assignment – Shamir's Secret Sharing (Simplified)

## 🧩 Problem Statement

This project implements a simplified version of **Shamir's Secret Sharing algorithm** to recover the **constant term (c)** of a polynomial given a set of points. The Y-values are encoded in different numerical bases and must be decoded first.

We apply **Lagrange Interpolation** to reconstruct the secret.

---

## 🔧 Tech Stack

- Language: **C++**
- JSON Parsing: [nlohmann/json](https://github.com/nlohmann/json)
- Supports: 256-bit number operations using `__int128`
- Build with any IDE or command line using g++ (e.g., `g++ main.cpp -o secret`)

---

## 📂 Files

| File             | Description                                 |
|------------------|---------------------------------------------|
| `main.cpp`       | Core implementation                         |
| `testcase1.json` | First input test case                       |
| `testcase2.json` | Second input test case                      |
| `README.md`      | This documentation                          |

---

## 🔢 Input Format (JSON)

Each test case contains:
- `"keys"` section with `n` and `k`
- `x: { base, value }` mappings where:
  - `x` is the input
  - `value` is encoded in `base`

Example:
```json
{
  "keys": { "n": 4, "k": 3 },
  "1": { "base": "10", "value": "4" },
  "2": { "base": "2", "value": "111" }
}
```

---

## 📌 How It Works

1. Parse JSON and extract `k` values.
2. Decode each `value` using the specified base.
3. Use **Lagrange Interpolation** to reconstruct the polynomial.
4. Print the constant term `c`, which is the **secret**.

---

## 🧪 Sample Output

```bash
Secret from testcase1.json: 10
Secret from testcase2.json: 2485263734263885249099331638996072661726463316846
```

---

## 🚀 How to Run

Make sure you have `json.hpp` from nlohmann/json library.

```bash
g++ main.cpp -o secret
./secret
```

---

## 📬 Submission

This GitHub repository contains:
- Source code
- Test cases
- Output and instructions

Feel free to contact for clarification. Good luck!