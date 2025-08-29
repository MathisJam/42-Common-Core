#!/usr/bin/env python3
import os
import cgi

print("Content-Type: text/html\n")
print("<html><body>")
print("<h1>CGI Python Test</h1>")

# Affiche les variables d'environnement CGI utiles
print("<h2>Environnement CGI</h2><ul>")
for var in ["REQUEST_METHOD", "QUERY_STRING", "SCRIPT_NAME", "PATH_INFO", "CONTENT_TYPE"]:
    print(f"<li>{var}: {os.environ.get(var, '')}</li>")
print("</ul>")

# Affiche les paramètres GET/POST
form = cgi.FieldStorage()
print("<h2>Paramètres GET/POST</h2><ul>")
for key in form.keys():
    print(f"<li>{key} = {form.getvalue(key)}</li>")
if not form.keys():
    print("<li>(Aucun)</li>")
print("</ul>")

print("</body></html>")

import sys

