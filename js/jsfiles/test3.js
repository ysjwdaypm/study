

function Vector(x,y){
	this.x = x;
	this.y = y;

	this.updateLen = function(){
		this.len = Math.sqrt(this.x * this.x + this.y * this.y);
	}

	this.loadIndenty = function(){
		this.x = this.x / this.len;
		this.y = this.y / this.len;
		this.updateLen();
		return this;
	}

	this.multiply = function(dis){
		this.x *= dis;
		this.y *= dis;
		this.updateLen();
	}

	this.multiplyVec = function(vec){
		return this.x * vec.y + this.y * vec.x;
	},

	this.project = function(vec){
		var data2 = this.multiplyVec(vec);
		var data1 = vec.len * this.len;
		var cos = data2 / data1; 
		var l = cos * vec.len;
		this.loadIndenty();
		this.multiply(l);
	}

	this.reflect = function(vec){

	}

	this.reverseNew = function(){
		return new Vector(-this.x, -this.y);
	}

	this.reverse = function(){
		this.multiply(-1);
	}

	this.addNew = function(v){
		return new Vector(this.x + v.x, this.y + v.y);
	}

	this.add = function(v){
		this.x += v.x;
		this.y += v.y;
		this.updateLen();
	}

	this.sub = function(v){
		this.x -= v.x;
		this.y -= v.y;
		this.updateLen();
	}

	this.toString = function(){
		return "vector x = " + this.x + "  , y = " + this.y + " , this.len = " + this.len;
	}

	this.updateLen();
}

function Point(x,y){
	this.x = x;
	this.y = y;

	this.add = function(x,y){
		if(typeof(x) === "Point"){
			this.x += x.x;
			this.y += x.y;
		}
		this.x += x;
		this.y += y;
	}

	this.equal = function(p){
		return this.x == p.x && this.y == p.y;
	}

	this.toString = function(){
		return "x = " + this.x + " , y = " + this.y;
	}
}



function Line(f,t){
	this.f = f;
	this.t = t;


	this.init = function(){
		var dx = this.t.x - this.f.x;
		var dy = this.t.y - this.f.y;
		if(dx == 0){//
			this.k = null;
			this.b = this.t.x;
		}else{
			this.k = dy / dx;
			this.b = this.f.y - this.k * this.f.x;	
		}
	}

	this.toString = function(){
		return "Line  this.k  = " + this.k + " , this.b = " + this.b;
	}

	this.normalLine = function(){
		var cos = Math.cos(Math.PI / 2);
		var sin = Math.sin(Math.PI / 2);
		var center_x = (this.f.x + this.t.x) / 2;
		var center_y = (this.f.y + this.t.y) / 2;

		var fx = this.f.x - center_x;
		var fy = this.f.y - center_y;
		var newFx = cos * fx - sin * fy + center_x;
		var newFy = sin * fx + cos * fy + center_y;

		var tx = this.t.x - center_x;
		var ty = this.t.y - center_y;
		var newTx = cos * tx - sin * ty + center_x;
		var newTy = sin * tx + cos * ty + center_y;

		return new Line(
				new Point(newFx, newFy),
				new Point(newTx, newTy)
			);
	}


	this.getX = function(y){
		return this.k == null?(this.b):(this.k == 0?(y == this.b?"any":null) : ((y - this.b) / this.k));
	}

	this.getY = function(x){
		return this.k == null?(x == this.b?"any":null):(this.k * x + this.b);
	}

	this.crossPointAlways = function(line){
		var x = null,y = null;
		if(this.k != line.k){
			if(this.k == null){
				x = this.b;
				y = line.getY(x);
				debug("----------------");
			}
			else
			{
				if(line.k == null){
					x = line.b;
					y = this.getY(x);
					debug("---------333333------- x  = " + x +  " y = " + y + " line " + line.toString());
				}
				else
				{
					//y = this.k * x + this.b;
					//y = line.k * x + line.b;
					x = (line.b - this.b) / (this.k - line.k);
					y = this.k * x + this.b;

					debug("---------444444-------");
				}
			}
		}

		return x != null && y != null?new Point(x,y):null;
	}

	this.crossPoint = function(line){
		var p = this.crossPointAlways(line);
		if(p){
			return this.pointOnline(p) && line.pointOnline(p);
		}

		return p;
	}

	this.pointOnline = function(p){
		return p.x >= Math.min(this.f.x, this.t.x) && p.x <= Math.max(this.f.x, this.t.x);
	}

	this.hitVector = function(v,c){
		var normalLine = this.normalLine();
		debug(normalLine.toString());
		if(c){
			normalLine.b = c.y - normalLine.k * c.x;
		}

		debug(normalLine.toString());
		var _crossPoint = this.crossPointAlways(normalLine);
		if(_crossPoint){
			debug(_crossPoint.toString());
			var vec = new Vector(c.x - _crossPoint.x, c.y - _crossPoint.y);
			vec.project(v);
			debug("vec = " + vec.toString());
			vec.multiply(2);
			debug("vec = " + vec.toString());
			vec.add(v);
			return vec;
		}

  		// a + b == >c 
		return null;
	}

	this.init();
}

var line = new Line(new Point(0, 0),new Point(200, 0));
var v1 = new Vector(-4, 4);

var v = line.hitVector(v1,new Point(100,100));
if(v){
	debug("adadadad    " + v.toString());
}
else
{
	debug("can't hit");
}
