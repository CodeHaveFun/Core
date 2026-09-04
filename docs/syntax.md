
## Construct Syntax <label style="color:grey;font-size:18px">*The syntax is NOT finalized and may change in future*</label> UPD: `Sep-3-2026`
The syntax will continue to improve in the future.
### 0. Comment: `//` `#` `;`
- Core supports three single-line comment styles: <br>
    ```co
    // This is a comment 
    # This is a comment 
    ; This is a comment


    set a = 0  // Comment
    ```
#### NOTE: Currently, Core does not support multi-line comments in this version.

### 1. Variable Definition: `set`
```core
set <name_variable> = <expression>
```
In which: 
- **I.** The `<name_variable>` name must: 
    1. Use ASCII or UTF-8 characters.

        ```core
        set score = 0   // ASCII
        set điểm = 0    // UTF-8
        ```
    2. Not contain spaces. Use `_` to connect words or start with. A variable name may also start with `_`.

        ```core
        set hello_world = "hello"   // VALID when combining use '_'
        set _hello_world = "hello"  // VALID, allow start with '_'


        set hello world = "hello"   // INVALID
                ^
        set hello-world = "hello"   // INVALID
                ^
        set hello.world = "hello"   // INVALID
                ^
        ```
    3. Not start with a number.

        ```core
        set a1 = 20     // VALID

        set 1a = 20     // INVALID, not start with a number
            ^
        ```
    4. Not contain unsupported special characters.

        ```core
        set user@name = "Danh"     // INVALID 
                ^ 
        set user$name = "Danh"     // INVALID
                ^
        ```
    5. Not be a reserved keyword.

        ```core
        set if = true       // INVALID
            ^^
        ```
    6. Follow Core's identifier case-sensitivity rules.

        ```core
        set score = 10 set Score = 20

        // 'score' and 'Score' are different identifiers.
        ```