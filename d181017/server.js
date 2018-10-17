/* Hello User
 * Use nodejs to generate a hello world web page for a user
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
"	</head>\n" +
"	<body>\n" +
"		<h1>HELLOOOO, WORLD!</h1>\n" +
"	</body>\n" +
"</html>\n";

// The server should repsond to all requests with a string
const server = http.createServer(function(req, res){

	// send a text response
	//res.end("Hello, world!\n");
	res.end(html);

});


// Start the server and have it listen on port 3000
server.listen(3000, function(){
	console.log("Server01 is listening on port 3000 now.");
});
