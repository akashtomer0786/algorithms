https://stackoverflow.com/questions/19673311/stl-vector-resize-and-assign

assign sets the size to n and all element values to 0.0, whereas resize sets the size to n and only new element values to 0.0.
If v is empty beforehand, they're the same, but assign is probably clearer.
