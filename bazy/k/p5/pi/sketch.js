function gen()  {
    return [x = Math.random(), y = Math.random()];
}

r = 100;
p = gen();
wys = 480;
szer = 640;

function setup() {
    createCanvas(640, 480);
    background('#0dffac');
}

function draw() {
    ellipse(szer /2, wys/2, 2*r, 2*r);
}
