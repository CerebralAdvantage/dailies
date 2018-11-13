/* Hello User
 * Use nodejs to generate a web page for a user with a big blue square on it
 */

// Dependencies
const http = require("http");

const html = "" +
"<!DOCTYPE html>\n" +
"<html lang=\"en\">\n" +
"	<head>\n" +
"		<meta charset=\"UTF-8\">\n" +
"		<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n" +
"		<meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\">\n" +
"		<title>Document</title>\n" +
"		<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n" +
"	</head>\n" +
"	<body>\n" +
"		<div id=\"bs\"></div>\n" +
"	</body>\n" +
"</html>\n";

const css = "" +
"*{ position: absolute; }\n" + 
"body{ margin: 0px; padding: 0px; }\n" +
"#bs { height: 100px; width: 100px; left: 300px; top: 150px; background-color: #33F; }\n";

// The server should repsond to all requests with a string
const server = http.createServer(function(req, res){

	if(req.url == '/')
		res.end(html);

	if(req.url == '/style.css')
		res.end(css);			// Take THAT, fs!

});


// Start the server and have it listen on port 3000
server.listen(3000, function(){
	console.log("Server01 is listening on port 3000 now.");
});
