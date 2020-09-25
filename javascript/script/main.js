let resolution;
let width;
let height;
let universe;

function setup() {
    resolution = 10;
    width = 60;
    height = 60;
    createCanvas(width * resolution, height * resolution);
    universe = createUniverse(width, height);
    colorMode(HSB);
}

function draw() {
    background(0);
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (universe[i][j] == 1) {
                rect(i * resolution, j * resolution, resolution, resolution);
            }
        }
    }
    var NGUniverse = createUniverse(width, height);
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            var neighbors = countNeighbors(i, j)
            if (universe[i][j] == 0 && neighbors == 3 || universe[i][j] == 1 && (neighbors == 2 || neighbors == 3))
                NGUniverse[i][j] = 1;
            else
                NGUniverse[i][j] = 0;
        }
    }
    universe = NGUniverse;
}

function createUniverse(n, m) {
    var arr = new Array(n);
    for (i = 0; i < n; i++) {
        arr[i] = new Array(m);
        for (j = 0; j < m; j++) {
            arr[i][j] = Math.floor(Math.random() * 2);
        }
    }
    return arr;
}

function countNeighbors(row, col) {
    var count = 0;
    for (var i = -1; i < 2; i++) {
        for (var j = -1; j < 2; j++) {
            count += universe[(row + i + width) % width][(col + j + height) % height];
        }
    }
    count -= universe[row][col];
    return count;
}