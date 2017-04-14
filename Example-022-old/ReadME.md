<A href="http://www.opengl.org"><IMG src='https://www.khronos.org/assets/images/api_logos/opengl.png' border=0 width="180" 
height="97"></A>

<H3>The <i>'Example-022 (Old Mode)'</i> Test</H3>

The <i>'Example-022 (Old Mode)'</i> Test draws 3 approximations of the <i>'Circle'</i> shape with radius <i>'R'</i> and center <i>'(xc,yc)'</i> in an <A href="http://www.opengl.org"><i>OpenGL</i></A> window. The approximations of interest are activated upon request, and are formed by an arbitrary number <i>'n'</i> of samples.<p>The <i>'Circle'</i> shape is defined as follows:<p><pre>| x(t) - xc | <= R * cos(t), | y(t) - yc | <= R * sin(t)</pre><p>for any <i>'R'>0</i>, and for every <i>'t'</i> in <i>'[-pi,pi]'</i>.<p>This test also provides a very basic interaction mechanism with the user, which must provide the radius <i>'R'</i> and the center <i>'(xc,yc)'</i>. The user can:<p><ul>
<li>approximate the boundary (in <i>'red'</i>) of the <i>'Circle'</i> shape through a polyline with an arbitrary number <i>'n'</i> of vertices and edges [ <i>'Approximation #0'</i> ] by pressing the <i>'l'</i> key.<p></li>
<li>Approximate the <i>'Circle'</i> shape through the <i>'filled versions'</i> of <i>'n'</i> triangles in a triangle fan [ <i>'Approximation #1'</i> ] by pressing the <i>'f'</i> key. All triangles (in <i>'dark gray'</i>) are incident at the center <i>'(xc,yc)'</i>, depicted in <i>'red'</i>.<p></li>
<li>Approximate the <i>'Circle'</i> shape through the <i>'filled version'</i> of only one polygon (in <i>'red'</i>) with <i>'n</i> vertices and edges [ <i>'Approximation #2'</i> ] by pressing the <i>'p'</i> key.<p></li>
<li>Increase the number <i>'n'</i> of the samples in the approximation of interest by pressing the <i>'+'</i> key.<p></li>
<li>Decrease the number <i>'n'</i> of the samples in the approximation of interest by pressing the <i>'-'</i> key.<p></li></ul><p>Likewise, the window of interest can be closed by pressing any among the <i>'Q'</i>, the <i>'q'</i>, and the <i>'Esc'</i> keys.<p><table border=0 width=100%><tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf0_case0.png' border='1' width='456' height='450'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf0_case1.png' border='1' width='456' height='450'></td></tr>
<tr><td><i>'Approximation #0'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=3</i>.</td><td><i>'Approximation #0'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=50</i>.</td></tr>
<tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf1_case0.png' border='1' width='456' height='450'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf1_case1.png' border='1' width='456' height='450'></td></tr>
<tr><td><i>'Approximation #1'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=3</i>.</td><td><i>'Approximation #1'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=50</i>.</td></tr>
<tr>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf2_case0.png' border='1' width='456' height='450'></td>
<td width=50%><IMG style=float:middle src='http://davidcanino.github.io/img/shots_opengl/shot_example022_conf2_case1.png' border='1' width='456' height='450'></td></tr>
<tr><td><i>'Approximation #2'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=3</i>.</td><td><i>'Approximation #2'</i>, <i>'R'=1</i>, <i>'(xc,yc)'=(0,0)</i>, and <i>'n'=50</i>.</td></tr></table><p><hr><p>

<h4>Dependencies</h4>

The <i>'Example-022 (Old Mode)'</i> Test is based on the so-called <i>OpenGL old (direct drawing) mode</i>, and requires the following dependencies:<ul>

<li>the <A href="http://www.opengl.org"><i>OpenGL</i></A> package, distributed with the platform of interest (see the <i><A href="https://www.khronos.org/opengl/wiki/Getting_Started">Official Documentation</A></i>);</li>
<li>the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> package (or the <A href="http://freeglut.sourceforge.net/"><i>FreeGLUT</i></A> package);</li>
<li>the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> package.</li></ul><p>In particular, this test consists of the <i>'Example-022-old'</i> executable file (in the <i><code>'bin'</code></i> folder), starting uniquely from the <i>'main.cpp'</i> C++ source file (in the <i><code>'src'</code></i> folder).<p>Several methods for building this test are provided.<p><table border=1><tr><td><p><b>ATTENTION:</b><p>The majority of the dependencies for this test are stable, but are currently deprecated, and several warning messages may appear during the building process.<p></td></tr></table><p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://cmake.org">CMake Building Tool</A></i></h4>

This test is built by using the <i>classic</i> instructions for building a program with the <i><A href="http://cmake.org">CMake Building Tool</A></i> from the <i><code>'cmake\'</code></i> folder:
<pre>mkdir build
cd build
cmake ..
make
</pre><p>As mentioned above, the <i>'Example-022-old'</i> executable file is created in the <i><code>'bin'</code></i> folder. For instance, this test is executed by running:<pre>./bin/Example-022-old</pre><p>This building method is tested with the <A href="http://gcc.gnu.org/"><i>GCC</i></A> under the Ubuntu Linux 16.0.4 (LTS), as well as with the <A href="http://clang.llvm.org/"><i>CLANG</i></A> compiler under the MacOsX 11.* El-Capitan (and higher), and the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A> under the Microsoft Windows 10.<p>In this latter case, three custom projects are automatically generated, and ready to be open in the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. The solution file of interest is the <i>'Example-022-old.sln'</i> solution file, which can be exploited directly in the program without being modified. This test is built by clicking on the <i>'Build'</i> command. The resulting <i>'Example-022-old.exe'</i> executable file is stored in the <i><code>'bin\Debug'</code></i> folder.<p>

All dependencies of the <i>'Example-022 (Old Mode)'</i> Test are supported automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i> through a built-in manifest file. In particular, they are often pre-installed in a generic GNU/Linux distribution, and distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Thus, they should be found by the script of interest without problems in these platforms.<p>Instead, these libraries are not standard in the Microsoft Windows, and must be installed properly. For the sake of simplicity, the Win32 versions for the auxiliary libraries of interest in the <i><code>'depends'</code></i> folder are exploited, if the <i><A href="http://cmake.org">CMake Building Tool</A></i> fails while performing their automatic identification. This means that the resulting solution file creates automatically the <i>'Example-022-old.exe'</i> Win32 executable file.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i></h4>

This test is also built by using the <A href="http://www.visualstudio.com/"><i>Microsoft Visual Studio (Community Edition 2015)</i></A>. In particular, the <i><code>'vstudio\'</code></i> folder contains the <i>'Example-022-old.sln'</i> solution file, which can be exploited directly in the program without being modified. This test is built by clicking on the <i>'Build'</i> command. The resulting <i>'Example-022-old.exe'</i> executable file is stored in the <i><code>'bin\Debug\'</code></i> folder.

Note that this solution file is independently created from scratch, and is different from the solution file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.

Specifically, the Win32 versions for the auxiliary libraries of interest in the <i><code>'depends\'</code></i> folder are exploited for building the <i>'Example-022 (Old Mode)'</i> Test. This implies that the <i>'Example-022-old.sln'</i> solution file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert. Furthermore, it is mandatory to enable the building for a generic Win32 platform for creating correctly the <i>'Example-022-old.exe'</i> Win32 executable file.<p>An interested user finds more details in the Official Documentation of the <i><A href="http://www.visualstudio.com/">Microsoft Visual Studio (Community Edition 2015)</A></i>.<p><hr><p>

<h4>Instructions for building this test with the <i><A href="http://developer.apple.com/xcode/">Apple XCode</A></i></h4>

This test is also built by using the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A> (based on the <A href="http://clang.llvm.org/"><i>CLANG</i> compiler</A>) under the MacOsX 11.* El-Capitan (and higher). In particular, the <i><code>'xcode'</code></i> folder contains the <i>'Example-022-old.xcodeproj'</i> project file, which can be exploited directly in the program without being modified. This test is built by clicking on the <i>'Build & Run'</i> command. The resulting <i>'Example-022-old'</i> executable file is stored in the <i><code>'Build/Products/Debug/'</code></i> folder, if the debugging symbols are included, or in the <i><code>'Build/Products/Release/'</code></i> folder, otherwise.<p>

Note that this project file is independently created from scratch, and is different from the project file, which may be generated automatically by the <i><A href="http://cmake.org">CMake Building Tool</A></i>.<p>

Specifically, this project file includes the versions (frameworks) of the <A href="http://www.opengl.org"><i>OpenGL</i></A> and of the <i><A href="https://www.opengl.org/resources/libraries/glut/">OpenGL Utility Toolkit (GLUT)</A></i> packages, that are distributed in conjunction with the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>. Instead, the headers and the library files of the <A href="http://glew.sourceforge.net/"><i>OpenGL Extension Wrangler Library (GLEW)</i></A> are assumed to be stored in the <i><code>'usr/local/include/'</code></i> and the <i><code>'usr/local/lib/'</code></i> folders, respectively. This implies that the <i>'Example-022-old.xcodeproj'</i> project file is set up for including these auxiliary libraries, and it should not be modified, unless you are an expert.<p>An interested user finds more details in the Official Documentation of the <A href="http://developer.apple.com/xcode/"><i>Apple XCode</i></A>.<p><hr><p><table border=1><tr><td><p><b>ATTENTION:</b><p>This test is not related officially to the <i><A href="https://www.khronos.org/">Khronos Group</A></i>. All trademarks or registered trademarks are the property of their respective owners.</td></tr></table>
