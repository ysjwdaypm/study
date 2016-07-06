var cons = new Array();
var ws = require('ws').Server;
var server = new ws({host:"192.168.1.45",port:8086});
server.on('connection',function(ws){
    console.log('new connection founded successfully');
    cons.push(new Soc(ws,currentRoomIndex));
    ws.on('message',function(data){
        console.log("get data from client = " + data);
        handlerDataFromClient(data,ws);
    });
    ws.on('close',function(){
        for(var i=0;i<cons.length;i++){
            if(cons[i].ws == ws) cons.splice(i,1);
        }
    });
});
console.log('websocket-server running...');


function User(x,y,sid){
    this.x = x;
    this.y = y;
    this.sid = sid;
}

function Soc(ws,roomid){

    this.ws = ws;
    this.roomid = roomid;

    this.sendToRoom = function(data,ws){
        var o = JSON.parse(data);
        var rid = o[1];
        if(rid == this.roomid && ws != this.ws){
            this.ws.send(data);
        }
    }

    this.send = function(data){
        this.ws.send(data);
    }

}


function Room(){

    this.userList = [];
    this.roomMaxUsers = 2;

    this.currentUserIndex = 1;

    this.addUser = function(user){
        this.userList.push(user);
        this.currentUserIndex++;
        if(this.userList.length >= this.roomMaxUsers){
            this.startGame();
        }
    }

    this.full = function(){
        return this.currentUserIndex == 1;
    }

    this.getUserInfo = function(){
        var ret = [];

        for(var i = 0;i < this.userList.length;i++){
            var user  = this.userList[i];
            ret.push({x:user.x,y:user.y,id:user.sid});
        }

        return ret;
    }

    this.startGame = function(){

        console.log("start info = " + info);
        var data = {"type":"start","userlist":this.getUserInfo(),"rid":currentRoomIndex};
        var info = JSON.stringify(data);

        for(var i=0;i<cons.length;i++){
            cons[i].send(info);
        }
        this.clear();

    }

    this.clear = function(){
        this.userList.length = 0;
        this.currentUserIndex = 1;
    }
}

var position = [[4,14],[2,2]];
var room = new Room();
/**
 * 当前房间号码
 * @type {number}
 */
var currentRoomIndex = 0;

function getPosition(){
    return position[room.userList.length];
}

var id = 1;

function handlerDataFromClient(data,ws){
    var d = JSON.parse(data);
    var t = d[0];
    if(t == "enter"){
        var p = getPosition();
        var user = new User(p[0],p[1], room.currentUserIndex);
        ws.send(JSON.stringify({"type":"init","id":room.currentUserIndex,rid:currentRoomIndex}));
        room.addUser(user);
        if(room.full()){
            currentRoomIndex++;
        }
    }
    else if(t == "closeServer"){
        var p = null;
        console.log(p.x);
    }
    else
    {
        for(var i=0;i<cons.length;i++){
            cons[i].sendToRoom(data,ws);
        }
    }
}