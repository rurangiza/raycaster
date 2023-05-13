/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:03:45 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/13 13:27:44 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////
// Global Variables
////////////////////////////////////////////////////////////////////////////

const TILE_SIZE = 48;
const MAP_NUM_ROWS = 11;
const MAP_NUM_COLS = 15;

const RAY_LINE_LENGTH = 30

const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

const FOV_ANGLE = 60 * (Math.PI / 180);

const WALL_STRIP_WIDTH = 3; 
const NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;

////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////

class Map {
	constructor() {
		this.grid = [
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1],
			[1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1],
			[1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
		];
	}
	hasWallAt(x, y) {
		if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
			return true;
		var mapGridIndexX = Math.floor(x / TILE_SIZE);
		var mapGridIndexY = Math.floor(y / TILE_SIZE);
		return this.grid[mapGridIndexY][mapGridIndexX] != 0;
	}
	render() {
		for (var i = 0; i < MAP_NUM_ROWS; i++) {
			for (var j = 0; j < MAP_NUM_COLS; j++) {
				var tileX = j * TILE_SIZE;
				var tileY = i * TILE_SIZE;
				var tileColor = this.grid[i][j] == 1 ? "#222" : "#fff";
				stroke("#222");
				fill(tileColor);
				rect(tileX, tileY, TILE_SIZE, TILE_SIZE);
			}
		}
	}
}   

class Player {
	constructor() {
		this.x = WINDOW_WIDTH / 2;
		this.y = WINDOW_HEIGHT / 2;
		this.radius = TILE_SIZE / 7;
		this.turnDirection = 0; // -1 if left, +1 if right
		this.walkDirection = 0; // -1 if back, +1 if front
		this.rotationAngle = Math.PI / 2;
		this.moveSpeed = 3.0;
		this.rotationSpeed = 2 * (Math.PI / 180);
	}
	update() {
		this.rotationAngle += this.turnDirection * this.rotationSpeed;

		var moveStep = this.walkDirection * this.moveSpeed;

		var newPlayerX = this.x + Math.cos(this.rotationAngle) * moveStep;
		var newPlayerY = this.y + Math.sin(this.rotationAngle) * moveStep;

		if (!grid.hasWallAt(newPlayerX, newPlayerY)) {
			this.x = newPlayerX;
			this.y = newPlayerY;
		}
	}
	render() {
		noStroke();
		fill("black");
		circle(this.x, this.y, this.radius);
		//stroke("yellow");
		line(
			this.x,
			this.y,
			this.x + Math.cos(this.rotationAngle) * RAY_LINE_LENGTH,
			this.y + Math.sin(this.rotationAngle) * RAY_LINE_LENGTH
		);
	};
}

class Ray {
	constructor(rayAngle) {
		this.rayAngle = rayAngle;
	}
	render() {
		stroke("red");
		line(
			player.x,
			player.y,
			player.x + Math.cos(this.rayAngle) * RAY_LINE_LENGTH,
			player.y + Math.sin(this.rayAngle) * RAY_LINE_LENGTH
		);
	}
}

////////////////////////////////////////////////////////////////////////////
// Creating Classes
////////////////////////////////////////////////////////////////////////////

var grid = new Map();
var player = new Player();
var rays = [];

////////////////////////////////////////////////////////////////////////////
// User input
////////////////////////////////////////////////////////////////////////////

function keyPressed() {
	if (keyCode == UP_ARROW) {
		player.walkDirection = +1;
	} else if (keyCode == DOWN_ARROW) {
		player.walkDirection = -1;
	} else if (keyCode == RIGHT_ARROW) {
		player.turnDirection = +1;
	} else if (keyCode == LEFT_ARROW) {
		player.turnDirection = -1;
	}
}

function keyReleased() {
	if (keyCode == UP_ARROW) {
		player.walkDirection = 0;
	} else if (keyCode == DOWN_ARROW) {
		player.walkDirection = 0;
	} else if (keyCode == RIGHT_ARROW) {
		player.turnDirection = 0;
	} else if (keyCode == LEFT_ARROW) {
		player.turnDirection = 0;
	}
}

////////////////////////////////////////////////////////////////////////////
// Casting rays
////////////////////////////////////////////////////////////////////////////
function castAllRays() {
	var columnId = 0;

	// start first ray substracting half of the FOV
	var rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

	rays = [];

	// loop all columns casting the rays
	//for (var i = 0; i < 1; i++) {
	for (var i = 0; i < NUM_RAYS; i++) {
		var ray = new Ray(rayAngle);
		// TODO: ray.cast()
		rays.push(ray);
		rayAngle += FOV_ANGLE / NUM_RAYS;

		columnId++;
	}
}

////////////////////////////////////////////////////////////////////////////
// Rendering
////////////////////////////////////////////////////////////////////////////

function setup() {
	createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT)
}

function update() {
	player.update();
	castAllRays();
}

function draw() {
	update();

	grid.render();
	for (ray of rays) {
		ray.render();
	}
	player.render();
}