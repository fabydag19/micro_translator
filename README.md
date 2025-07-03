# Micro Translator

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![C](https://img.shields.io/badge/C-Programming%20Language-brightgreen)
![Last Commit](https://img.shields.io/github/last-commit/fabydag19/micro_translator)
![Repo Size](https://img.shields.io/github/repo-size/fabydag19/micro_translator)

This is a simple command line dictionary written in pure C that reads a small dataset of English-Italian words and allows users to translate the words interactively.

## Features

- Reads a CSV dataset of English–Italian word pairs
- Skips column headers automatically
- Matches English input words and returns their Italian translation
- Basic error handling for file access and missing words
- Written entirely in standard C (portable and lightweight)

## Requirements

- GCC or any standard C compiler
- A CSV file (`en_it_words.csv`) located in `dataset/`

## How to Run

```bash
gcc main.c -o translator
./translator
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
