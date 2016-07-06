
var handler = {

    hand : function (parma) {
        var list = parma.split("&");
        console.log(parma);
        this.write(parma);
    },

    write : function(info,path){

        var storePath = "log.txt";

        if(arguments.length == 2){
            storePath = arguments[1];
        }

        info +=  "     time:" + new Date().getTime() + "\n";

        var fs = require('fs');
        fs.appendFile(storePath,info,function(err){
           //if(err)throw err;
            //console.log("wtite successfull");
        });
    },

    read : function (res) {
        var fs = require('fs');
        fs.readFile("log.txt", function(err,data){
            if(err) throw err
            res.end(data.toString());
        });
    }
}


/*
 创建文件

 var fileName = "anps_hsj";
 fs.mkdir(fileName,function(err){
 if(err) throw err
 console.log("创建文件成功");
 fs.exists( fileName ,function(exists){
 console.log(exists ? "文件存在了，不能重新创建了" : "文件不存在，文件创建失败了");
 });
 });
 */

/*
 写入内容到文件中，不会追加,如果文件没有即会立即创建

 var fileName = "anps.txt";
 var content = "hello word\n";
 fs.writeFile(fileName,content,function(err){
 if(err) throw err
 console.log("success");
 });
 */

/*
 写入内容到文件中，会追加,如果文件没有即会立即创建
 var fileName = "anps.txt";
 var content = "hello word\n";
 fs.appendFile(fileName,content,function(err){
 if(err) throw err
 console.log("success");
 });
 */

/*
 文件删除
 fs.unlink("Copy of anps.txt", function(err){
 fs.exists("Copy of anps.txt", function(exists){
 console.log(exists ? "删除失败" : "删除成功");
 });
 });
 */

/*
 文件读取
 fs.readFile("anps.txt", function(err,data){
 if(err) throw err
 console.log(data.toString());
 });
 */

/*
 读取目录

 fs.readdir("E:\\2015_WorkSpace\\nodejsPro\\anps_hsj", function(err,files){
 for(var i = 0 ; i < files.length; i ++){
 console.log(files[i]); // 文件名称
 var fileName = files[i];
 fs.readFile("E:\\2015_WorkSpace\\nodejsPro\\anps_hsj\\"+files[i], function(err,data){
 if(err) throw err
 console.log(fileName+"文本内容是:"+data.toString());
 });
 }
 });

 */

var ip = "192.168.1.140";

var http = require('http');
http.createServer(function (req, res) {
    //res.writeHead(200, {'Content-Type': 'text/plain'});
    //res.end('Hello World\n');
    // 设置接收数据编码格式为 UTF-8
    req.setEncoding('utf-8');
    var postData = ""; //POST & GET ： name=zzl&email=zzl@sina.com
    // 数据块接收中
    req.addListener("data", function (postDataChunk) {
        postData += postDataChunk;
    });
    // 数据接收完毕，执行回调函数
    req.addListener("end", function () {
        handler.hand(postData);
    });
}).listen(1337, ip);


//var query = require('http');
http.createServer(function(req,res){

    res.writeHead(200, {'Content-Type': 'text/plain;charset=utf-8'});
    handler.read(res);

}).listen(1338,ip);

console.log('Server running at http://192.168.1.140:1337/');