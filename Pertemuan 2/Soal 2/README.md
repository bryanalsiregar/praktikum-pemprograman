# Folder untuk soal nomor 2
### Pertemuan 2 (03/09/2024)

Folder untuk penyelesaian nomor 2 <br>

Soal: <br>
You are given a quadratic equation of the form

$$
ax^2 + bx + c = 0
$$

where a, b, and c are coefficients. Your task is to write a C++ program to solve the
quadratic equation and find the values of x.
The quadratic formula for solving the equation is:

$$
x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
$$

Here’s what you need to do:
1. Write a C++ program that prompts the user to input the coefficients a, b, and c
one by one.
2. Calculate the discriminant:
$$
∆ = b^2 − 4ac
$$
3. Use the quadratic formula to calculate the roots:
    - If $∆ > 0$, there are two distinct real roots:
    $$
    x_1 = \frac{−b +\sqrt{∆}}{2a}
    $$
    $$
    x_2 = \frac{−b − \sqrt{∆}}{2a}
    $$
    - If $∆ = 0$, there is exactly one real root:
    $$
    x = \frac{−b}{2a}
    $$
    - If $∆ < 0$, there are no real roots (the roots are complex).
4. Output the results accordingly.