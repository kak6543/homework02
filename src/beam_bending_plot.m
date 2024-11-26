clc; clear all; close all;

% load data from CSV file
data = readmatrix('/System/Volumes/Data/Users/kseniakirsanova/homework02/src/beam_bending_data.csv');

% x (length along the beam) and y (deflection)
x = data(:, 1);
y = data(:, 2);

figure;
plot(x, y, 'b-', 'LineWidth', 2);
title('Beam Bending - Cantilever Beam with Uniform Load');
xlabel('Length along the beam (m)');
ylabel('Deflection (m)');
grid on;
