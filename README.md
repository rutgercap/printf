# ft_printf

A library that contains ft_printf, a c function that mimics the real printf. 

## Project goals
The project is part of the [Codam](https://www.codam.nl/studying-at-codam) curriculum. The main learning goals were to learn about:
- Variable argument lists
- Writing good scalable code

## Usage

**Prototype:**

```c
int	ft_printf(const char *str, ...)
```

**Supported flags:**

- Width

- Precision

- '-0.*' and all combinations

**Supported conversions:**

cspdiuxX%

**Return value:**

The amount of characters printed as int

## Small disclaimer

The entire project is written in accordance with the 42 Network Norm. The norm puts readability above everything and can therefore sometimes be limiting in terms of writing the most optimal code.
