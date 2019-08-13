<?php
$dbconnect = mysqli_connect("localhost","root","");
$dbselect = mysqli_select_db($dbconnect,"myhome");
$sql = "SELECT * from status";
$result = mysqli_query($dbconnect,$sql);
$row=mysqli_fetch_assoc($result);
if(isset($_GET['tubelight'])){
	$t = $_GET['tubelight'];
}
else{
	$t = $row["tubelight"];
}
if(isset($_GET['lamp'])){
	$l = $_GET['lamp'];
}
else{
	$l = $row["nightlamp"];
}
if(isset($_GET['fan'])){
	$f = $_GET['fan'];
}
else{
	$f = $row["fan"];
}
if(isset($_GET['ac'])){
	$a = $_GET['ac'];
}
else{
	$a = $row["ac"];
}
echo "t".$t."l".$l."f".$f."a".$a;

mysqli_query($dbconnect,"TRUNCATE TABLE status");
$sql = "INSERT INTO status VALUES('$t','$l','$f','$a')";
mysqli_query($dbconnect,$sql);

?>