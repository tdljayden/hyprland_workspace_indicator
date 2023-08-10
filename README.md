# hyprland_workspace_indicator

## What is it?

A multi-monitor workspace indicator JSON output for use with EWW and Hyprland.
It is super lightweight and written in C. It supports up to 10 workspaces [1,2,3,4,5,6,7,8,9,0].

The key feature is the ability to see individual workspaces on each monitor respectively, reducing clutter and increasing readability. For example, you might see one numbered workspace (4) on one monitor, and 3 other numbered workspaces (7,8, and 9) on another monitor.

![image](https://github.com/tdljayden/hyprland_workspace_indicator/assets/110114652/0d491ba9-899f-4704-a6cd-4ef93a32f8ff)

## What do you need to know?

The program will not work with any wayland compositors that aren't Hyprland. The program produces a JSON output for each monitor like this:

```json
[
  {
    "activeworkspaces": [
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false,
      false
    ],
    "workspaces": [
      false,
      false,
      false,
      false,
      false,
      true,
      true,
      false,
      true,
      false
    ]
  }
]
```

## How to build and install (eww)

Build requirements:
* cJSON
* Make

1. Run `make`
2. Edit the workspaces_script in `bin/` to the path of the binary (which is produced in the `bin/` directory by default).
3. Set a `deflisten` variable in eww with the workspaces_script as the input.
4. Create a `defwidget` that uses that variable for `:reveal` or `:visible` as seen by the example code in `example/`.
5. Implement the widget in a `defwindow`, like your eww bar for example.
