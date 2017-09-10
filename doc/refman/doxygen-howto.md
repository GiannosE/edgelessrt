Using Doxygen in OpenEnclave
============================

This short document explains how to use Doxygen within OpenEnclave.

## Overview

Doxygen is used to extract documentation from the OpenEnclave source code.
This directory contains a makefile for building all Doxygen output formats
including:

- HTML (html directory)
- XML (xml directory)
- LaTeX (latex directory)
- Markdown (md directory)

The xml2md tool is used to generate Markdown format (from Doxygen-generated
XML files). The generated Markdown files are the only ones that are checked
into the Github repository. This allows one to brose the documentation from
the Github site.

All output formats are generated from this directory by typing

```
$ make
```

or from the top-level directory by typing;

```
$ make refman
```

## Adding headers files to the Doxygen input list

To add new header files to be processed by Doxygen, edit this file (in the
current directory).

```
doxygen.conf
```

Append new sources to the `INPUT` variable.

## Source-code documentation conventions

OpenEnclave uses the Doxygen Markdown style througout the sources. To learn
more about Doyxgen Markdown, see:

[link][https://www.stack.nl/~dimitri/doxygen/manual/markdown.html]

The sections below explain the basics.

*Note:* the xml2md tool only supports the Mardown features described in this
document.

### Comment blocks

In OpenEnclave, Doxygen comment blocks are defined as follows.

```
/**
 *
 *
 */
```

### Brief description

The brief description is the first sentence that appears in the comment block,
terminated by a period.

```
/**
 * This is my brief description.
 */
```

### Detailed description

The detailed description follows the brief description.

```
/**
 * This is my brief description.
 *
 * This is my detailed description. It may contain many sentences.
 */
```

### Parameters

Parameters should be introduced as follows.

```
/**
 * ...
 *
 * @param param1 This is my first parameter.
 * @param param2 This is my second parameter.
 */
```
#### Return values

Return value may be specified as a list of paragraphs (`@retval`) or
as a single paragrah (`@returns`).

Here's an example of a list of paragraphs:

```
/**
 * ...
 *
 * @retval 0 The function was successful.
 * @retval -1 The function failed.
 */
```

Here's an example of a single paragraph:

```
/**
 * ...
 *
 * @returns Returns OK on success.
 */
```

### Emphasis

To emphasize text (italics), use single asterisks as follows.

```
/**
 * This is my *emphasis* example.
 *
 */
```

### Boldface

To bold text, use double asterisks as follow.

```
/**
 * This is my *bold* example.
 *
 */
```

### Lists

Lists are introduced by the hyphen character as follows.

```
/**
 * ...
 *
 * This is my list:
 *
 * - Sunday
 * - Monday
 * - Tuesday
 * - Wednesday
 * - Thursday
 * - Friday
 * - Saturday
 *
 */
```

### Verbatim

To define a verbatim block of text, separate it by blank lines and indent it.
For example.

```
/**
 * ...
 *
 * This is my verbatim text:
 *
 *   This is my verbatim block of text.
 *
 * Continue with normal text.
 *
 */
```