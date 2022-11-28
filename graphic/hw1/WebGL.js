var VSHADER_SOURCE = `
    attribute vec4 a_Position;
    attribute vec4 a_Color;
    varying vec4 v_Color;
    void main(){
        gl_Position = a_Position;
        v_Color = a_Color;
        gl_PointSize = 5.0;
    }
    `;

var FSHADER_SOURCE = `
    precision mediump float;
    varying vec4 v_Color;
    void main(){
        gl_FragColor = v_Color;
    }
    `;

var nowShape = 1;
var nowColor = 1;
var dotData = [];
var circleData = [];
var squareData = [];
var triangleData = [];

function compileShader(gl, vShaderText, fShaderText){
    //////Build vertex and fragment shader objects
    var vertexShader = gl.createShader(gl.VERTEX_SHADER)
    var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER)
    //The way to  set up shader text source
    gl.shaderSource(vertexShader, vShaderText)
    gl.shaderSource(fragmentShader, fShaderText)
    //compile vertex shader
    gl.compileShader(vertexShader)
    if(!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)){
        console.log('vertex shader ereror');
        var message = gl.getShaderInfoLog(vertexShader); 
        console.log(message);//print shader compiling error message
    }
    //compile fragment shader
    gl.compileShader(fragmentShader)
    if(!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)){
        console.log('fragment shader ereror');
        var message = gl.getShaderInfoLog(fragmentShader);
        console.log(message);//print shader compiling error message
    }

    /////link shader to program (by a self-define function)
    var program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    //if not success, log the program info, and delete it.
    if(!gl.getProgramParameter(program, gl.LINK_STATUS)){
        alert(gl.getProgramInfoLog(program) + "");
        gl.deleteProgram(program);
    }

    return program;
}

function main(){
    var canvas = document.getElementById('webgl');

    var gl = canvas.getContext('webgl2');
    if(!gl){
        console.log('Failed to get the rendering context for WebGL');
        return ;
    }

    let renderProgram = compileShader(gl, VSHADER_SOURCE, FSHADER_SOURCE);
 
    gl.useProgram(renderProgram);
    
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    canvas.onmousedown = function(ev){click(ev, gl, canvas, renderProgram.a_Position, renderProgram.a_Color, renderProgram)}
}

function click(ev, gl, canvas, a_Position, a_Color, program){
    
    var x = ev.clientX;
    var y = ev.clientY;
    var rect = ev.target.getBoundingClientRect();
    
    //get the x and y
    // console.log("x: " + x);
    // console.log("y: " + y);
    x = (x - 208) / 200;
    y = -(y - 207) / 200;
    // console.log("x: " + x);
    // console.log("y: " + y);

    //store shape
    if(nowShape == 1)     pushDot(x, y);
    else if(nowShape == 2)pushCircle(x, y);
    else if(nowShape == 3)pushTriangle(x, y);
    else if(nowShape == 4)pushSquare(x, y);

    //draw all the shapes
    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT); 

    drawDot(gl, program);
    drawTriangle(gl, program);
    drawSquare(gl, program);
    drawCircle(gl, program);
}

function pushColor(dataList){
    if(nowColor == 1)      dataList.push(1, 0, 0);  
    else if(nowColor == 2) dataList.push(0, 0, 1);
    else if(nowColor == 3) dataList.push(0, 1, 0);
    else if(nowColor == 4) dataList.push(1, 1, 1);
    else if(nowColor == 5) dataList.push(0.6484375, 0.40234375, 0.8125);
}

function pushDot(x, y){

    if(dotData.length >= 15) dotData.splice(0, 5);

    dotData.push(x, y);
    pushColor(dotData);

    // console.log("dotData: " + dotData);
}

function pushCircle(x, y){
    if(circleData.length >= 4500) circleData.splice(0, 1500);

    for(i = 0 ; i < 100 ; i++){
        var rad = (i * 3.6) * Math.PI / 180;
        var rad2 = ((i + 1) * 3.6) * Math.PI / 180;
        //first point
        circleData.push(x, y);
        pushColor(circleData);

        //second point
        circleData.push(x + 0.1 * Math.cos(rad), y + 0.1 * Math.sin(rad));
        pushColor(circleData);

        //third point
        circleData.push(x + 0.1 * Math.cos(rad2), y + 0.1 * Math.sin(rad2));
        pushColor(circleData);
    }
}

function pushTriangle(x, y){
    if(triangleData.length >= 45) triangleData.splice(0, 15);

    //top point
    triangleData.push(x, y + 0.2 * 0.5773502691896258);
    pushColor(triangleData);

    //bottom left point
    triangleData.push(x - 0.1, y - 0.2 * 0.2886751345948129)
    pushColor(triangleData);

    //bottom right point
    triangleData.push(x + 0.1, y - 0.2 * 0.2886751345948129)
    pushColor(triangleData);
}

function pushSquare(x, y){
    if(squareData.length >= 90) squareData.splice(0, 30);

    //top left
    squareData.push(x - 0.06, y + 0.06);
    pushColor(squareData);
    
    //top right
    squareData.push(x + 0.06, y + 0.06);
    pushColor(squareData);

    //bottom left
    squareData.push(x - 0.06, y - 0.06);
    pushColor(squareData);

    //top right
    squareData.push(x + 0.06, y + 0.06);
    pushColor(squareData);

    //bottom left
    squareData.push(x - 0.06, y - 0.06);
    pushColor(squareData);

    //bottom right
    squareData.push(x + 0.06, y - 0.06);
    pushColor(squareData);
}

function drawDot(gl, program){
    
    var n = dotData.length / 5;
    if(n == 0) return; //no point to draw

    var vertexData = new Float32Array(dotData);
    // console.log("vertexData: " + vertexData);

    var buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexData, gl.STATIC_DRAW);

    var FSIZE = vertexData.BYTES_PER_ELEMENT;
   
    var a_Position = gl.getAttribLocation(program, 'a_Position');
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0);
    gl.enableVertexAttribArray(a_Position);

    var a_Color = gl.getAttribLocation(program, 'a_Color');
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2);
    gl.enableVertexAttribArray(a_Color);

    gl.drawArrays(gl.POINTS, 0, n);
}

function drawCircle(gl, program){

    var n = circleData.length / 5;
    if(n == 0) return; //no circle to draw

    var vertexData = new Float32Array(circleData);

    var buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexData, gl.STATIC_DRAW);

    var FSIZE = vertexData.BYTES_PER_ELEMENT;
   
    var a_Position = gl.getAttribLocation(program, 'a_Position');
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0);
    gl.enableVertexAttribArray(a_Position);

    var a_Color = gl.getAttribLocation(program, 'a_Color');
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2);
    gl.enableVertexAttribArray(a_Color);

    gl.drawArrays(gl.TRIANGLES, 0, n);
}

function drawTriangle(gl, program){

    var n = triangleData.length / 5;
    if(n == 0) return; //no triangle to draw

    var vertexData = new Float32Array(triangleData);

    var buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexData, gl.STATIC_DRAW);

    var FSIZE = vertexData.BYTES_PER_ELEMENT;
   
    var a_Position = gl.getAttribLocation(program, 'a_Position');
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0);
    gl.enableVertexAttribArray(a_Position);

    var a_Color = gl.getAttribLocation(program, 'a_Color');
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2);
    gl.enableVertexAttribArray(a_Color);

    gl.drawArrays(gl.TRIANGLES, 0, n);
}

function drawSquare(gl, program){
    var n = squareData.length / 5;
    if(n == 0) return; //no square to draw

    var vertexData = new Float32Array(squareData);

    var buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertexData, gl.STATIC_DRAW);

    var FSIZE = vertexData.BYTES_PER_ELEMENT;
   
    var a_Position = gl.getAttribLocation(program, 'a_Position');
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0);
    gl.enableVertexAttribArray(a_Position);

    var a_Color = gl.getAttribLocation(program, 'a_Color');
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2);
    gl.enableVertexAttribArray(a_Color);

    gl.drawArrays(gl.TRIANGLES, 0, n);
}

document.onkeydown=function(e){
    var keyNum=window.event ? e.keyCode :e.which;
    if(keyNum == 68)  nowShape = 1; //Dot
    if(keyNum == 67)  nowShape = 2; //Circle
    if(keyNum == 84)  nowShape = 3; //Triangle
    if(keyNum == 83)  nowShape = 4; //Square
    if(keyNum == 82)  nowColor = 1; //Red
    if(keyNum == 66)  nowColor = 2; //Blue
    if(keyNum == 71)  nowColor = 3; //Green
    if(keyNum == 87)  nowColor = 4; //White
    if(keyNum == 80)  nowColor = 5; //Purple
}

function initVertexBuffers(gl, program){
    var vertices = new Float32Array(
        [ -0.5, 0.5, 1.0, 0.0, 0.0,
           0.5, 0.5, 1.0, 1.0, 1.0,
          -0.5,-0.5, 1.0, 1.0, 1.0,
           0.5,-0.5, 0.0, 0.0, 1.0]
        //TODO-1: vertex and color array
    );

    var n = 4;

    var vertexBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);

    var FSIZE = vertices.BYTES_PER_ELEMENT;
   
    var a_Position = gl.getAttribLocation(program, 'a_Position');
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0);
    gl.enableVertexAttribArray(a_Position);

    var a_Color = gl.getAttribLocation(program, 'a_Color');
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2);
    gl.enableVertexAttribArray(a_Color);

    gl.drawArrays(gl.TRIANGLES_FAN, 0, n);
    return n;
}