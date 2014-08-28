module til308() {
  assign(w = 0.42)
  assign(h = 1.05)
  assign(d = 0.14)
  assign(pin_w = 0.3)
  assign(pin_h = 0.17)
  assign(notch_r = (w - pin_w) / 4) {
    color("silver")
    for (x=[-1,1], ysign=[-1,1], y=[0:3]) {
      translate([x * 0.3 / 2 * 25.4, ysign * (y * 0.1 + 0.05) * 25.4, -0.17 / 2 * 25.4]) 
      cylinder(r=0.56/2, h=0.17*25.4, center=true, $fn=10);
    }

    color("black")
    translate([0, 0.25 * 25.4, 2]) 
    cube(size=[4.2, 6.4, 1], center=true);

    color("black")
    translate([0, -.15 * 25.4, 2]) 
    cube(size=[2, 2, 1], center=true);

    color("red", 0.6)
    translate([0, 0, d / 2 * 25.4]) 
    difference() {
      cube(size=[w * 25.4, h * 25.4, d * 25.4], center=true);
      for (x=[-1,1], y=[-1,1]) {
        translate([x * w / 2 * 25.4, y * (4 * 0.1 * 25.4), 0])
          cylinder(r=notch_r * 25.4, h=10, center=true, $fn=16); 

        translate([x * (w / 2 - notch_r * 2) * 25.4, y * (h / 2) * 25.4, 0])
          cylinder(r=notch_r * 25.4, h=10, center=true, $fn=16);

        translate([x * w / 2 * 25.4, y * h / 2 * 25.4, d / 2 * 25.4]) 
          cylinder(r=notch_r * 25.4, h=2, center=true);
      }
    }
  }
}

til308();