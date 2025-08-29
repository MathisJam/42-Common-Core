<?php
$visits = 1;
if (isset($_COOKIE['visit_count'])) {
    $visits = intval($_COOKIE['visit_count']) + 1;
}
setcookie('visit_count', $visits, time() + 3600*24*365, "/");
header('Content-Type: application/json');
echo json_encode(['visits' => $visits]);
