#<center>**小学生四则运算数据库设计说明书**</center>
***

<h2 id='1'>1.数据库说明书</h2> 
&emsp;&emsp;使用SQL Sever数据库，Visual Studio编程工具  
&emsp;&emsp;  
<h2 id='2'>2.数据库命名法</h2> 
&emsp;&emsp;数据库采用小驼峰命名法  
&emsp;&emsp;    
<h2 id='3'>3.逻辑设计</h2>
<center>![](http://i.imgur.com/nntwVdG.png)</center>
&emsp;&emsp;    
<h2 id='4'>4.物理设计</h2>
<h3 id='4.0'>4.0 表汇总</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>表名</td>
   <td>功能说明</td>
 </tr>
 <tr>
   <td>User</td>
   <td>用户信息表</td>
 </tr>
 <tr>
   <td>Admin</td>
   <td>管理员信息表</td>
 </tr>
 <tr>
   <td>CalQuestion</td>
   <td>四则运算题表，包括内容、结果等</td>
 </tr>
 <tr>
   <td>Test</td>
   <td>测试信息表，用户进行测试的相关信息</td>
 </tr>
 <tr>
   <td>TestCalQuestion</td>
   <td>测试与四则运算题关系表</td>
 </tr>
 </table>
<h3 id='4.1'>4.1 User表</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>列名</td>
   <td>数据类型</td>
   <td>是否可空</td>
   <td>约束条件</td>
 </tr>
 <tr>
   <td>userName</td>
   <td>String</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>userKey</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>userGrade</td>
   <td>Int</td>
   <td>Y</td>
   <td></td>
 </tr>
 </table>
<h3 id='4.2'>4.2 Admin表</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>列名</td>
   <td>数据类型</td>
   <td>是否可空</td>
   <td>约束条件</td>
 </tr>
 <tr>
   <td>adName</td>
   <td>String</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>userKey</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 </table>
<h3 id='4.3'>4.3 CalQuestion表</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>列名</td>
   <td>数据类型</td>
   <td>是否可空</td>
   <td>约束条件</td>
 </tr>
 <tr>
   <td>calQueNum</td>
   <td>Long</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>calQueContent</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>calQueResult</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>testType</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 </table>
<h3 id='4.4'>4.4 Test表</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>列名</td>
   <td>数据类型</td>
   <td>是否可空</td>
   <td>约束条件</td>
 </tr>
 <tr>
   <td>testNum</td>
   <td>String</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>testType</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>testCount</td>
   <td>Int</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>userName</td>
   <td>String</td>
   <td>N</td>
   <td>FK</td>
 </tr>
 <tr>
   <td>testRightNum</td>
   <td>Int</td>
   <td>N</td>
   <td></td>
 </tr>
 <tr>
   <td>testTime</td>
   <td>String</td>
   <td>N</td>
   <td></td>
 </tr>
 </table>
<h3 id='4.5'>4.5 TestCalQuestion表</h3>
<table class="table table-bordered table-striped table-condensed">
 <tr>
   <td>列名</td>
   <td>数据类型</td>
   <td>是否可空</td>
   <td>约束条件</td>
 </tr>
 <tr>
   <td>testNum</td>
   <td>String</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>calQueNum</td>
   <td>String</td>
   <td>N</td>
   <td>PK</td>
 </tr>
 <tr>
   <td>isRight</td>
   <td>char</td>
   <td>N</td>
   <td></td>
 </tr>
 </table>