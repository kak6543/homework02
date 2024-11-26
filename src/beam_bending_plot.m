% **** to run in MATLAB, have to first type cd homework02/src and then type beam_bending_plot in your 
% MATLAB terminal
clc; clear all; close all;

% load data from CSV file
data = readmatrix('beam_bending_data.csv');

% x (length along the beam) and y (deflection)
x = data(:, 1);
y = data(:, 2);

figure;
plot(x, y, 'b-', 'LineWidth', 2);
title('Beam Bending - Cantilever Beam with Uniform Load');
xlabel('Length along the beam (m)');
ylabel('Deflection (m)');
grid on;

