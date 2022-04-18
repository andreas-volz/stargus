DefineAnimations("animations-bengalaas-jungle-critter", {
  Still = {
    "frame 0", "wait 125",
  },
})

DefineUnitType("Bengalaas-(Jungle-Critter)", { Name = "Bengalaas (Jungle Critter)",
  Image = {"file", "neutral/units/bengalaas jungle critter.png", "size", {128, 128}},
  Shadow = {"file", "neutral/units/bengalaas jungle critter shadow.png", "size", {128, 128}},
  Animations = "animations-bengalaas-jungle-critter", Icon = "icon-bengalaas-jungle-critter",
  NeutralMinimapColor = {0, 228, 252},
  Speed = 0,
  HitPoints = 20,
  DrawLevel = 5,
  TileSize = {2, 1}, BoxSize = {63, 31},
  SightRange = 0,
  BasicDamage = 0, PiercingDamage = 0, Missile = "missile-none",
  Priority = 0,
  Type = "land",
  LandUnit = true,
  organic = true,
})