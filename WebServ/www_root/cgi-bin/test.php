<?php
// filepath: /home/mjameau/Documents/WebServ/www_root/cgi-bin/test.php
header("Content-Type: text/html");
echo "<html><body>";
echo "<h1>CGI PHP Test</h1>";

// Affiche les variables d'environnement CGI utiles
echo "<h2>Environnement CGI</h2><ul>";
foreach (["REQUEST_METHOD", "QUERY_STRING", "SCRIPT_NAME", "PATH_INFO", "CONTENT_TYPE"] as $var) {
    echo "<li>$var: " . (getenv($var) ?: "") . "</li>";
}
echo "</ul>";

// Affiche les paramètres GET/POST
echo "<h2>Paramètres GET/POST</h2><ul>";
if (empty($_REQUEST)) {
    echo "<li>(Aucun)</li>";
} else {
    foreach ($_REQUEST as $key => $value) {
        echo "<li>$key = $value</li>";
    }
}
echo "</ul>";

echo "</body></html>";
?>
