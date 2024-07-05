Version 0.10.3 For Dev-C++ 7 Beta
 - enhancement: add option "ignore spaces when validating problem cases" to the "Executor"/"Problem Set" option tab.

Version 0.10.2 For Dev-C++ 7 Beta
 - fix: select by mouse can't correctly set mouse's column position
 - fix: dragging out of the editor and back will cause error
 - fix: dragging text from lines in the front to lines back will cause error
 - fix: dragging text onto itself should do nothing
 - fix：license info in the about dialog should be readonly
 - enhancement: change project name in the project view

Version 0.10.1 For Dev-C++ 7 Beta
 - fix: can't correctly expand watch expression that has spaces in it
 - fix: can't correctly display stl containers in watch
 - fix: the last line in the debug console is not correctly displayed
 - enhancement: scroll while dragging text in the editor
 - fix: dragging out of the editor shouldn't reset the caret back 

Version 0.10.0 For Dev-C++ 7 Beta
 - enhancement: use gdb/mi interface to  communicate with gdb debug session
 - enhancement: better display of watch vars
 - fix: project's modified flag not cleared after saved

Version 0.9.4 For Dev-C++ 7 Beta
 - fix: code formatter's "indent type" option not correctly saved

Version 0.9.3 For Dev-C++ 7 Beta
 - fix: the count in the title of issues view isn't correct
 - fix: columns calculation not correct when paint lines containing chinese characters
 - fix: restore caret position after reformat code
 - enhancement: ask user to rebuild project, when run/debug the project and it has been modified
 - fix: correct set the enabled state of "delete line"/"insert line"/"delete word"/"delete to BOL"/"delete to EOL" menu items
 - fix: undo "delete word"/"delete to BOL"/"delete to EOL" correct reset caret position

Version 0.9.2 For Dev-C++ 7 Beta
 - fix: gutter of the disassembly code control in the cpu info dialog is grayed
 - fix: problem set & problem views not correctly hidden when disabled in the executor / problem set options 
 - fix: executor / problem set options not correctly saved
 - fix: option "Move caret to the first non-space char in the current line when press HOME key" dosen't work fine.
 - fix: ctrl+left can't correctly move to the beginning of the last word
 - enhancement: add "delete line"/"duplicate line"/"delete word"/"delete to EOL"/"delete to BOL" in the edit menu
 - fix: crash when run "Project" / "Clean Make files"
 - fix: when make project and del non-existing files, shouldn't show error messages

Version 0.9.1 For Dev-C++ 7 Beta
 - enhancement: code completion suggestion for "__func__" variable
 - fix: ide failed to start, if there are errors in the compiler set settings
 - fix: numpad's enter key doesn't work
 - enhancement: code completion suggestion for phrase after long/short/signed/unsigned
 - enhancement: save/load default projects folder
 - enhancement: add editor general options "highlight current word" and "highlight matching braces"

Version 0.9.0 For Dev-C++ 7 Beta
 - fix: control keys in the numpad doesn't work in the editor
 - fix: project layout infos are wrongly saved to registry 
 - fix: project layout infos are not correctly saved/loaded

Version 0.8.11 For Dev-C++ 7 Beta
 - fix: text color for cpu info dialog not correctly setted

Version 0.8.10 For Dev-C++ 7 Beta
 - fix: Shouldn't update auto link settings, if the header name to be modified is unchanged
 - fix: add unit to project not correctly set new unit file's encoding
 - fix: correctly set encoding for the new added project unit file
 - fix: if there's a project openned, new file should ask user if he want to add the new file to the project
 - fix: when adding a file openned in the editor to the project, properties of it are not correctly setted.
 - enhancement: when remove a file from the project, also ask if user want to remove it from disk
 - fix: double click a project's .dev file in the Files panel should load the project

Version 0.8.9 For Dev-C++ 7 Beta
 - fix: text color of labels in statusbar not correctly updated when change theme

Version 0.8.8 For Dev-C++ 7 Beta
 - enhancement: drag & drop text in the editor
 - enhancement: auto calcuate caret line size basing on font size
 - enhancement: shift+mouse wheel to scroll horizontally 
 - fix: greatly reduces paste time 
 - fix: auto indent shouldn't use preprocessor's indent to calculate 
 - fix: option "don't add leading zeros to line numbers" not work
 - fix: "collapse all" and "uncollapse all" doesn't work

Version 0.8.7 For Dev-C++ 7 Beta
 - enhancement: auto indent line to column 1 when enter '#' at beginning of line
 - fix: when enter '{' or '}' at beginning of line, auto indent will remove all contents of the line
 - fix: auto indent should be turned off when reformat code
 - fix: auto indent should be turned off when replace in code 

Version 0.8.6 For Dev-C++ 7 Beta
 - enhancement: greatly reduces memory usage for symbol parsing ( memory needed for bits/stdc++.h reduced from 150m+ to 80m+)
 - fix: currect compiler set not correctly updated when switch between normal file and project file
 - fix: editor auto save settings not saved and applied
 - fix: only auto save files that has new modifications 
 - fix: correctly auto save files with it's own name

Version 0.8.5 For Dev-C++ 7 Beta
 - enhancement: use lighter color to draw menu seperators
 - enhancement: differentiate selected and unselected tab bars

Version 0.8.4 For Dev-C++ 7 Beta
 - enhancement: auto save/load the default open folder in the configuration file
 - fix: shouldn't auto add '()' when char succeeding the completed function name is '('
 - fix: can't show code completion popup if symbol is proceed with an operator '~' ( and it's not a destructor)
 - fix: can't show code completion popup when define MACRO
 - fix: can't debug files with chinese characters in the path

Version 0.8.3 For Dev-C++ 7 Beta
 - enhancement: View menu
 - enhancement: hide/show statusbar
 - enhancement: hide/show left/bottom tool window bars
 - enhancement: hide/show individual left/bottom tool window

Version 0.8.2 For Dev-C++ 7 Beta
 - fix: highlighter can't correctly find the end of ANSI C-style Comments
 - enhancement: add default color scheme to themes. Change theme option will change color scheme too.
 - fix: when changing options in the option dialog's color scheme panle, color of the demo editor won't be not correctly updated
 - enhancement: auto clear parsed symbols when the editor is hidden ( to reduce memory usage of un-active editors)
 - fix: when inputing in the editor, correctly set the position of the input method panel
 - fix: correctly display watch & local variable names when debugging

Version 0.8.1 For Dev-C++ 7 Beta
 - fix: ConsolePaurser.exe only exits when press ENTER
 - fix: input/output/expected textedit in the problem view shouldn't autowrap lines
 - fix: Red Panda C++ will freeze when receiving contents from Competitve Companion in chrome/edge
 - enhancement: when problem from competitive companion received, activate RedPanda C++ if it's minimized.
 - enhancement: when problem from competitive companion received, show the problem and problem set views.
 - enhancement: set problem's answer source file 
 - enhancement: open the problem's answer source file in editor
 - fix: if the proceeding line ends with ':' in comments, current line should not indent
 - enhancement: right click the problem set name label to rename it
 - change: memory view and locals view use debug console's font settings
 - fix: one line 'while' statement dosen't correctly indents
 - fix: line start with  '{' that follow an un-ended 'if'/'for' statement is not correctly un-indented
 - fix: multi-line comments indents calculation
 - fix: Installer should install the app in "program files", not "program files (x86)"
 - fix: symbol completion for '/*' not work
 - fix: javadoc-style docstring indents calculation
 - fix: indents calculation for the line succeeding "*/"

Version 0.8 For Dev-C++ 7 Beta
 - fix: find in the current file is not correcly saved in the search history
 - fix: hit info not correctly displayed in the search result view
 - fix: If find in files found no hits, search result view will not be shown.
 - fix: wront indents when paste one line content
 - fix: Results of "find symbol usage" in project not correctly set in the search result view
 - change: turn on gcc compiler's "-pipe" option by default, to use pipe instead of temp files in compiliation (and make the life of SSD longer)
 - fix: correctly save input histories for the find combo box in the Find dialog
 - fix: can't correctly test if it's not running in green mode

Version 0.7.8
 - enhancement: In problem view's output control, indicates which line is different with the expected
 - fix: current input/expected not correctly applied when save/run problem cases
 - fix: colors of the syntax issues view are not correctly set using the current color sheme
 - change: The error color of color scheme "vs code" 
 - add: "C Reference" in the help menu
 - fix: Custom editor colors shouldn't be tested for high contrast with the default background color
 - fix: Custom color settings not correctly displayed in the options widget
 - enhancement: add hit counts in the search result view
 - fix: editor actions' state not correctly updated after close editors.
 - fix: When replace in the editor, "Yes to All" and "No" button doesn't work correctly.
 - fix: crash when editing non-c/c++ files
 - enhancement: set the alpha value of scheme colors
 - enhancement: can use symbols' own foreground color to draw selection or the current line
 - enhancement: can use different colors to highlight the current word and the selections
 - enhancement: can set editor's default background / foreground color. They must be setted to make the custom color schemes correctly.
 - enhancement: can set the color for the current line's number in the gutter
 - all predefined color schemes updated. 
 - enhancement: check syntax/parse symbols when modifed and cursor's line changed.
 - enhancement: edit problem properties
 - enhancement: show problem description in the problem name lable's tooltip

Version 0.7.7
 - enhancement: Problem Set 
 - enhancement: Competitive Companion Support
 - change: "save" action will be enabled no matter contents in the current editor is modified or not
 - fix: focus not correctly set when the current editor is closed
 - fix: can't parse old c-style enum variable definition like "enum Test test;"
 - fix: remove the file change monitor if it's remove from the disk
 - fix: don't test if a file is writable before save to it (because qt can't do that test reliably).
 - fix: when search in project, files opened for search shouldn't be parsed for symbols.
 - fix: when search in project, the search history is not correctly updated.

Version 0.7.6
 - change: don't auto insert a new line when input an enter between '(' and ')' or between '[' and ']' (indent instead)
 - enhancement: the line containing '}' will use the indents of the matching '{' line, instead of just unindent one level
 - enhancement: the line containing 'public:' / 'private:' / 'protected:' / 'case *:' will use of indents of the surrounding '{' line, instead of just unindent one level
 - enhancement: correctly handle auto indents for multi-level embedding complex statements like 'for(...) if (...) printf();
 - change: Don't use 'pause' in the console pauser, in case of privilege problems.
 - enhancement: correctly handle auto indents for statement span many lines;
 - enhancment: only use colors have good contrasts with the background in the class browser and code completion suggestion window
 - fix: bottom and left panel properties not correctly saved when hiding the main window
 - fix: When debugging, if value of the variable pointed by the mouse cursor is too long, tooltip will fill the whole screen.

Version 0.7.5
 - enhancement: more accurate auto indent calculation
 - change: remove "add indent" option in the editor general options widget ( It's merged with "auto indent" option)
 - enhancement: auto insert a new line when input an enter between '(' and ')' or between '[' and ']'
 - fix: correctly updates cursor position when pasting from clipboard
 - enhancement: auto unindent when input protected: public: private: case *:
 - enhancement: can use PageDown / PageUp / Home / End to scroll in the auto completion popup

Version 0.7.4
 - fix: when debug a project, and have breakpoints that not in opened editors, dev-cpp will crash
 - fix: when a file is parsing in background, exit dev-cpp will crash
 - fix: "tab to spaces" option in the editor general options widget doesn't work
 - fix: when remove all breakpoints in the debug breakpoint view,  debug tags in the opened editors are not correctly updated.
 - change: when start debuging, show local view instead of the debug console.
 - update bundled compiler to msys2 mingw-w64 gcc 11.2 and gdb 10.2
 - update bundled xege to the lastest git build

Version 0.7.3
 - enhancement: icons in project view
 - fix: sometimes option widget will show confirm dialog even not changed
 - enhancement: only editor area will receive file drop events
 - enhancement: change project file's folder by drag and drop in the project view
 - enhancement: open project file by drag it to the editor area
 - fix: the "add bookmark" menu item is not correctly disabled on a bookmarked line
 - enhancement: "use utf8 by default" in editor's misc setting
 - fix: syntax issues not correctly cleared when the file was saved as another name.
 - enhancement: when running a program, redirect a data file to its stdin
 - fix: can't correctly handle '&&' and '||' in the #if directive (and correctly parse windows.h header file)
 - fix: crash when create an empty project
 - fix: syntax issues' filepath info not correct when build projects 
 - fix: compiler autolinks options widget don't show autolink infos
 - fix: autolink parameters are repeated when compile single files
 - enhancement: prompt for filename when create new project unit file
 - fix: options not correctly set when change compiler set in the project settings
 - change: reset compiler settings when change the project compiler set
 - enhancement: use project's compiler set type info to find a nearest system compiler set, when the project compiler set is not valid.
 - fix: toolbar's compiler set info not correctly updated when change it in the project settings dialog.

Version 0.7.2
 - fix: rainbow parenthesis stop functioning when change editor's general options
 - fix: issue count not correctly displayed when syntax check/compile finished
 - fix: function declaration's parameters not correctly parsed, if it have a definition which have different parameter names
 - fix: file path seperator used in the app is not unified, and cause errors somtimes.


Version 0.7.1
 - fix: can't add bookmark at a breakpoint line
 - fix: app name in the title bar not translated
 - use new app icon

Version 0.7.0
 - fix: Backspace still works in readonly mode
 - fix: save as file dialog's operation mode is not correct
 - enhancement: fill indents in the editor (Turned off by default)
 - enhancement: new file template
 - fix: when an editor is created, its caret will be displayed even it doesn't have focus
 - enhancement: set mouse wheel scroll speed in the editor general option tab ( 3 lines by default)
 - fix: don't highlight '#' with spaces preceeding it as error
 - fix: correctly handle integer with 'L' suffix in #if directives ( so <thread> can be correctly parsed )
 - enhancement: bookmark view
 - enhancement: autosave/load bookmarks
 - enhancement: autosave/load breakpoints 
 - enhancement: autosave/load watches
 - implement: files view
 - fix: app's title not update when editor closed

Version 0.6.8
 - enhancement: add link to cppreference in the help menu
 - fix: add mutex lock to prevent editor crash in rare conditions
 - fix: In the create project dialog, the browser button doesn't work
 - enhancement: use QStyle to implement the dark style, and better control of the style's look and feel 
 - enhancement: add link to EGE website, if locale is zh_CN

Version 0.6.7
 - fix: messages send to the gdb process's standard error are not received
 - adjust: the max value of the debug console's vertical scrollbar.
 - fix: shfit+click not correctly set selection's end
 - fix: ctrl+home/end not correctly set cursor to start/end of the editor
 - enhancement: click the encoding info in the statusbar will show encoding menu

Version 0.6.6
 - fix: crash when create new file
 - implement: two editor view

Version 0.6.5
 - implement: export as rtf / export as html
 - fix: the contents copied/exported are not correctly syntax colored
 - fix: stop execution if the source file is not compiled and user choose not to compile it
 - fix: not correctly parse gdb's output
 - fix: path not correctly setted for the debugger process
 - fix: indent line not correctly drawed
 - enhancement: use rainbox color to draw indent guide lines
 - implement: highlight matching brackets

Version 0.6.4
 - fix: code completion popup not show after '->' inputted
 - fix: font styles in the color scheme settings not in effect
 - fix: editor's font style shouldn't affect gutter's font style
 - change: enable copy as HTML by default
 - fix: unneeded empty lines when copy as HTML

Version 0.6.3
 - fix: should use c++ syntax to check ".h" files
 - fix: can't copy contents in a readonly editor
 - fix: project's file not correctly syntaxed when open in editor
 - libturtle update: add fill() / setBackgroundColor() /setBackgroundImage() functions
 - fix: code fold calculation not correct, when editing code
 - fix: can't correctly find definition of the symbols in namespace
    
Version 0.6.2 
 - fix: The Enter key in the numpad doesn't work
 - fix: The compiled executable not fully write to the disk before run it
 - fix: settings object not correctly released when exit
 - fix: shouldn't check syntax when save modifications before compiling
 - fix: shouldn't scroll to the end of the last line when update compile logs
 - fix: can't debug project

Version 0.6.1
 - fix: editor deadlock

Version 0.6.0
 - fix: old data not displayed when editing code snippets
 - fix: shift-tab for unindent not work
 - fix: can't save code snippets modifications
 - fix: errors in code snippet processing
 - change: auto open a new editor at start
 - enhancement: todo view
 - add: about dialog
 - implement: correctly recognize clang (msys2 build)
 - enhancement: don't add encoding options when using clang to compile (clang only support utf-8)
 - enhancement: find occurence in project
 - implement: rename symbol in file
 - enhancement: replace in files
 - enhancement: rename symbol in project (using search symbol occurence and replace in files)
 - fix: search in files
 - implement: register file associations
 - implement: when startup , open file provided by command line options
 - implement: open files pasted by clipboard
 - fix: code fold parsing not correct
 - enhancement: support #include_next (and clang libc++)
 - fix:  hide popup windows when the editor is closed
 - enhancement: show pinyin when input chinese characters
 - fix: add mutex lock to prevent rare conditions when editor is modifying and the content is read
 - fix: makefile generated for static / dynamic library projects not right
 - fix: editors disappeared when close/close all
 - implement: config shortcuts
 - implement: handle windows logout message
 - fix: editor's inproject property not correctly setted (and may cause devcpp to crash when close project)
 - implement: print
 - implement: tools configuration
 - implement: default settings for code formatter
 - implement: remove all custom settings

Version 0.5.0
 - enhancement: support C++ using type alias;
 - fix: when press shift, completion popu window will hide
 - enhancement: options in debugger setting widget, to skip system/project/custom header&project files when step into
 - fix: icon not correctly displayed for global variables in the class browser 
 - enhancement: more charset selection in the edit menu
 - fix: can't correctly get system default encoding name when save file
 - fix: Tokenizer can't correctly handle array parameters
 - fix: debug actions enabled states not correct updated when processing debug mouse tooltips
 - enhancement: redesign charset selection in the project options dialog's file widget
 - fix: can't correctly load last open files / project with non-asii characters in path
 - fix: can't coorectly load last open project
 - fix: can't coorectly show code completion for array elements
 - enhancement: show caret when show code/header completions
 - fix: correctly display pointer info in watch console
 - implement: search in project
 - enhancement: view memory when debugging
 - implement: symbol usage count
 - implement: user code snippet / template
 - implement: auto generate javadoc-style docstring for functions
 - enhancement: use up/down key to navigate function parameter tooltip
 - enhancement: press esc to close function parameter tooltip
 - enhancement: code suggestion for unicode identifiers
 - implement: context menu for debug console
 - fix: errors in debug console
 - fix: speed up the parsing process of debugger
 - ehancement: check if debugger path contains non-ascii characters (this will prevent it from work

Version 0.2.1
 - fix: crash when load last opens

Version 0.2
 - fix : header file completion stop work when input '.'
 - change: continue to run / debug if there are compiling warnings (but no errors)
 - enhancement: auto load last open files at start
 - enhancement: class browser syntax colors and icons
 - enhancement: function tips
 - enhancement: project support
 - enhancement: paint color editor use system palette's disabled group color
 - fix: add watch not work when there's no editor openned;
 - enhancement: rainbow parenthesis
 - enhancement: run executable with parameters
 - add: widget for function tips
 - enhancement: options for editor tooltips
 - fix: editor folder process error