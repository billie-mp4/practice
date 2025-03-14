const http=require('http')
const fs=require('fs')
const redirect=function(path){
  switch(path){
    case'/':return'index.html'
    case'/about':return'about.html'
    case'/contact':return'contact.html'
    default:return'404.html'
  }
}
http.createServer(function(req,res){
  fs.readFile(redirect(req.url),function(err,data){
    res.writeHead(200,{'Content-Type':'text/html'})
    res.write(data)
    res.end()
  })
}).listen(8080)
