var ct;

var ws;

var addrsss = "ws://192.168.1.166:8080";

var user_id = "1";

var tunkList = [];

var myTunk;
var myTunkData;

var screen_width = 960;
var screen_height = 640;



function addImage(context,l){
	context.save();

	context.translate(l[2],l[3]);
	console.log("translate:" + l[2] + " -- " + l[3] + " ,  rotate = " + l[4]);
	// context.rotate = 0;
	context.rotate(Math.PI * l[4] / 180);
	context.translate(-l[2],-l[3]);

	var img = new Image();
	img.src = "blog/aaa.jpg";
	if(img.complete){
		context.drawImage(img,0,0);
		// console.log("draw immed");
	}
	else
	{
		img.onload = function(){
			context.drawImage(img,0,0);
			// alert("onload success");
		}

		img.onerror = function(){
			// alert("load aaa.jpg fail");
		}
}

// context.rotate(-Math.PI * l[4] / 180);
// context.translate(-l[2],-l[3]);
// 

	context.restore();

	return img;
}

var context;
var imgArr = [];
var rotateArr = [];
var _x = 0;
function testLoop(){

	_x += 2;
	context.clearRect(0,0,1000,1000);
	for (var i = imgArr.length - 1; i >= 0; i--) {
		var img = imgArr[i];
		if(img)
		{
			context.save();
			context.translate(300,300);//开始移动画笔
			context.rotate(Math.PI * (rotateArr[i] + _x) / 180);
			context.drawImage(img,0,0)
			context.restore();
		}
	};
}

function start(){


var canvas = document.querySelector("#game");
context = canvas.getContext("2d");
// context.lineWidth = 12;

// context.strokeStyle = "black"
// context.strokeRect(0,0,100,100);

// context.strokeStyle = "red";

// context.rect(0,0,200,200);
// context.clip();

// context.beginPath();
// context.arc(200, 200, 100, (Math.PI/180)*0, (Math.PI/180)*360, false);
// context.stroke();
// context.closePath();

// context.beginPath();
// context.arc(220, 220, 100, (Math.PI/180)*0, (Math.PI/180)*360, false);
// context.stroke();
// context.closePath();



var v = document.querySelector("#name").value;
var l = v.split(":");

for (var i = 0; i < l.length; i++) {
	l[i] = parseInt(l[i]);
};

// addImage(context,l)

for (var i = 0; i < l[5]; i++) {
	var angle = 360 / l[5];
	img = addImage(context,[l[0],l[1],l[2] ,l[3],l[4] + angle * i]);
	rotateArr.push(l[4] + angle * i);
	imgArr.push(img);
};

// context.clearRect(0,0,1000,1000);
setInterval(testLoop,1000/30);

// addImage(context,[l[0],l[1],l[2] ,l[3],l[4] + 50]);
// addImage(context,[l[0],l[1],l[2] ,l[3],l[4] + 60]);
// addImage(context,[l[0],l[1],l[2] + 200,l[3],l[4] + 70]);
// addImage(context,[l[0],l[1],l[2] + 200,l[3],l[4] + 80]);

// addImage(context,[l[0],l[1],l[2] + 400,l[3],l[4] + 60]);

// addImage(context,[l[0],l[1],l[2] + 600,l[3],l[4] + 80]);
// addImage(context,[l[0] + 200,l[1],l[2] + 200,l[3],l[4] + 30]);

// addImage(context,[l[0] + 400,l[1],l[2] + 400,l[3],l[4] + 60]);

// addImage(context,[l[0] + 600,l[1],l[2] + 600,l[3],l[4] + 80]);
// 

context.restore();

context.strokeStyle = "green";
context.beginPath();
context.arc(130,130,130,0,Math.PI / 3,false);
context.stroke();
context.closePath();

context.beginPath();
context.arc(200, 200, 100, (Math.PI/180)*0, (Math.PI/180)*360, false);
context.stroke();
context.closePath();



context.beginPath();
context.arc(220, 220, 100, (Math.PI/180)*0, (Math.PI/180)*360, false);
context.stroke();
context.closePath();

// context.clearRect(0,0,300,300);
// img.src = null;

return;
//---------------------
	var c = document.querySelector("#game");
	this.ct = c.getContext('2d');
	this.ct.fillStyle = "#ffffff";
	this.ct.fillRect(0,0,screen_width,screen_height);

	setInterval(loop,1000/30);

	this.connectSocket();
	var o = {};
	o.name = document.querySelector("#name").value;
	o.x = screen_width / 2;
	o.y = screen_height - 100;
	o.width = 60;
	o.height = 60;
	this.myTunkData = o;

	this.myTunk = addTunk(o);


	document.onkeydown = eventHandler;
}


function connectSocket(){

	ws = new WebSocket(addrsss);

	ws.onopen = onopen;

	ws.onerror = function(){

	}

	ws.onclose = function(){
		ws.close();
		connectSocket();
	}
	ws.onmessage = onmessage;
}

function onopen(){
	sendData("create",myTunkData);
}

function  onmessage(evt){

	var d = evt.data;
	var o = JSON.parse(d);
	console.log("reciver:"+d);
	if(o.data.name != myTunkData.name){

		var action =  o.action;
		if(action == "create"){
			addTunk(o.data);
		}
		else if(action == "move"){
			moveTunk(o.data);
		}
	}
}


function moveTunk(data){
	var tunk = this.getTunkByName(data.name);
	if(tunk){
		tunk.updatePosition(data);
	}
	else
	{
		data.width = myTunkData.width;
		data.height = myTunkData.height;
		addTunk(data);
	}
}

function getTunkByName(name){

	for (var i = 0; i < this.tunkList.length; i++) {
		var tunk = this.tunkList[i];
		if(tunk.name == name){
			return tunk;
		}
	};

	return null;
}

function addTunk(o){
	var tunk = Tunk.createTunk(o.name,o.x,o.y,o.width,o.height);
	tunkList.push(tunk);
	return tunk;
}

function sendData(a,d){

	var o = {};
	o.action = a;
	o.data = d;
	o.name = this.myTunkData.name;
	console.log("send o = " + o.data);
	if(ws){
		var sendMsg = JSON.stringify(o);
		console.log("sendMsg:"+sendMsg);
		ws.send(sendMsg);
	}

}

function eventHandler(e){

	var evt = window.event || e;
	var code = evt.keyCode || evt.which;

	var speedX = 0;
	var speedY = 0;
	var speed = 3;
	switch(code){
		case 65://A
			speedX = -speed;
			break;
		case 87://W
			speedY = -speed;
			break;	
		case 68://D
			speedX = speed;
			break;	
		case 83://S
			speedY = speed;
			break;
		case 32://SPACE
			this.sendData("fire",myTunkData);
			break;		
	}

	if(speedX != 0 || speedY != 0){
		myTunkData.x += speedX;
		myTunkData.y += speedY;
		myTunk.updatePosition(myTunkData);
		sendData("move",myTunkData);
	}
}

currentFrame = 0;
function loop(){
	currentFrame++;
	document.querySelector("#msg").innerHTML = "UPDATE TIME:" + currentFrame;
	this.drawAll();
}



function drawAll(){

	ct.clearRect(0,0,screen_width,screen_height);

	for (var i = 0; i < this.tunkList.length; i++) {
		var tunk = this.tunkList[i];
		tunk.render(this.ct);
	};

}




var Tunk = {
	createTunk : function(name,x,y,width,height){
		var tunk = {};
		tunk.name = name;
		tunk.x = x;
		tunk.y = y;
		tunk.width = width;
		tunk.height = height;

		tunk.updatePosition = function(p){
			this.x = p.x;
			this.y = p.y;
		},

		tunk.render = function(ct){
			ct.fillRect(this.x,this.y,this.width,this.height);
			ct.strokeRect(this.x,this.y,this.width,this.height);
		}

		return tunk;
	}

}