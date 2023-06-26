<!DOCTYPE html>
<html>
<body>
  <h1>Pipex</h1>

  <p>
    This program allows you to execute a shell command pipeline similar to the following shell command: <code>&lt; file1 cmd1 | cmd2 &gt; file2</code>.
  </p>

  <h2>Usage</h2>

  <p>
    To run the program, use the following command format:
  </p>

  <pre>
    ./pipex file1 cmd1 cmd2 file2
  </pre>

  <p>
    Where:
  </p>

  <ul>
    <li><code>file1</code> and <code>file2</code> are the names of the input and output files respectively.</li>
    <li><code>cmd1</code> and <code>cmd2</code> are shell commands with their parameters.</li>
  </ul>

  <h2>Examples</h2>

  <p>
    Here are some examples to illustrate the usage of Pipex:
  </p>

  <pre>
    $ ./pipex infile "ls -l" "wc -l" outfile
  </pre>

  <p>
    This is equivalent to the shell command: <code>&lt; infile ls -l | wc -l &gt; outfile</code>
  </p>

  <pre>
    $ ./pipex infile "grep a1" "wc -w" outfile
  </pre>

  <p>
    This is equivalent to the shell command: <code>&lt; infile grep a1 | wc -w &gt; outfile</code>
  </p>

  <h2>Requirements</h2>

  <p>
    To ensure a successful execution of your project, please adhere to the following requirements:
  </p>

  <ul>
    <li>Include a Makefile that compiles your source files without relinking.</li>
    <li>Handle errors thoroughly to prevent unexpected program termination (e.g., segmentation faults, bus errors, double free, etc.).</li>
    <li>Avoid memory leaks in your program.</li>
    <li>If you encounter any doubt or error, handle it similar to the shell command: <code>&lt; file1 cmd1 | cmd2 &gt; file2</code></li>
  </ul>

  <h2>Getting Started</h2>
  <ol>
    <li>This program isn't much but is an introduction to minishell as it will be the way to execute program in parallel.</li>
    <li>The parsing is easy since the order is given.</li>
    <li>The hard part of the project is that the way the program is launched isn't instinctive.</li>
  </ol>

  <h2>Resources</h2>
  <ul>
    <li><a href="https://man7.org/linux/man-pages/man2/execve.2.html">Execve</a></li>
    <li><a href="https://www.section.io/engineering-education/fork-in-c-programming-language/">Fork</a></li>
    <li><a href="https://man7.org/linux/man-pages/man2/dup2.2.html">Dup2</a></li>
    
</body>
</html>
