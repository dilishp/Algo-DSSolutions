var http = require("http");
var express = require("express");
var ejsengine = require("ejs-locals");

var app = express();

app.engine('ejs', ejsengine); //For Master Page
app.set("view engine", "ejs"); //Setting the View Engine used to render the view

app.get("/", function (req, res) {
    res.render("ejs/index", { title: "Hello from Node" });
});

app.get("/app/user", function (req, res) {
    res.set("Content-Type", "application/json");
    res.send({ name: "dilish", Age: 25, email: "dilsihpoth@gmail.com" });
});

var server = http.createServer(app);

server.listen(3000);
