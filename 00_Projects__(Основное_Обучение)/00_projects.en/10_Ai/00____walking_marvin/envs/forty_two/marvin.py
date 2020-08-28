import sys, math
import numpy as np

import Box2D
from Box2D.b2 import (edgeShape, circleShape, fixtureDef, polygonShape, revoluteJointDef, weldJointDef, contactListener)

import gym
from gym import spaces
from gym.utils import colorize, seeding


FPS    = 50
SCALE  = 30.0

MOTORS_TORQUE = 80
SPEED_HIP     = 4
SPEED_KNEE    = 6
LIDAR_RANGE   = 160/SCALE

INITIAL_RANDOM = 5

BODY_SHAPE =[[(-9.84, 27.3), (-13.66, 30.8), (-16.82, 34.92), (-18.88, 39.52), (-20.48, 44.6), (-20.8, 50.16), (-20.0, 55.08), (-18.58, 59.52), (-16.2, 63.66), (-13.8, 66.98), (-10.96, 69.52), (-7.14, 72.38), (-2.7, 74.76), (2.38, 76.34), (6.98, 76.82), (12.38, 76.5)], [(-9.84, 27.3), (12.38, 76.5), (16.98, 75.24), (20.8, 73.5), (24.12, 71.26), (27.78, 68.1), (30.32, 65.08), (32.38, 61.9), (33.96, 58.42), (35.4, 53.8), (35.72, 49.84), (35.56, 46.2), (34.92, 42.38), (33.34, 37.94), (30.96, 33.8), (28.1, 30.32)], [(-9.84, 27.3), (28.1, 30.32), (24.44, 26.82), (21.12, 24.6), (16.98, 22.7), (11.74, 21.42)], [(11.74, 21.42), (12.38, 18.42), (12.22, 14.28), (13.02, 11.9), (-9.84, 27.3)], [(-9.84, 27.3), (13.02, 11.9), (-26.98, -1.12), (-27.3, 3.18), (-27.3, 5.24), (-27.46, 7.14), (-27.14, 8.58), (-25.4, 10.48), (-23.5, 12.06), (-21.58, 15.24), (-20.32, 18.42), (-18.88, 21.42), (-17.46, 23.02), (-14.92, 24.6), (-13.02, 24.76), (-9.2, 24.6)], [(13.02, 11.9), (14.28, 9.2), (16.98, 5.88), (19.52, 2.38), (23.02, -2.38), (24.44, -5.72), (26.2, -10.0)], [(13.02, 11.9), (26.2, -10.0), (26.82, -14.76), (23.8, -16.98), (19.68, -16.34), (16.82, -13.34), (15.56, -11.74), (13.34, -16.66), (2.86, -22.86), (-2.06, -23.5), (-11.12, -23.8), (-17.46, -23.18), (-21.12, -18.88), (-23.96, -13.02), (-26.04, -7.46), (-26.98, -1.12)]]

LEG_UPPER_SHAPE = [(-2.78, -3.17), (-0.32, -3.73), (2.22, -3.25), (4.05, -2.14), (4.76, -0.24), (4.44, 4.60), (0.56, 7.95), (-0.71, 7.81), (-1.90, 7.81), (-2.54, 7.81), (-2.62, 6.75), (-3.17, 5.08), (-3.81, 4.05), (-4.44, 2.30), (-4.52, 0.56), (-3.17, -2.86)]
LEG_UPPER_SHAPE = [(round(x/0.5, 2), round(-y/0.35, 2)) for x, y in LEG_UPPER_SHAPE]

LEG_LOWER_SHAPE = [(-3.57, 0.79), (-3.25, -0.63), (-2.22, -2.38), (0.08, -3.57), (1.51, -2.78), (2.62, -1.67), (4.52, 1.51), (4.05, 2.62), (8.17, 6.75), (8.17, 7.46), (6.27, 8.81), (-3.25, 8.41), (-3.41, 7.70), (-3.49, 6.03), (-3.49, 3.97)]
LEG_LOWER_SHAPE = [(round(x/0.5, 2), round(-y/0.35, 2)) for x, y in LEG_LOWER_SHAPE]

LEG_UPPER_DETAILS = [
    [(-1.67, 6.43), (-1.11, 6.51), (-0.95, 7.22), (-1.11, 7.94), (-1.67, 7.94), (-1.98, 7.38)],
    [(-0.79, 8.65), (0.08, 7.22), (0.48, 6.03), (0.95, 5.24), (4.05, 4.76), (4.05, 5.16), (0.63, 6.03), (0.08, 7.54)],
]
LEG_UPPER_DETAILS = [[(round(x/0.5, 2), round(-y/0.35, 2)) for x, y in shape] for shape in LEG_UPPER_DETAILS]

LEG_LOWER_DETAILS = [
    [(-0.79, 7.94), (-0.56, 7.46), (-0.40, 5.32), (-0.08, 4.29), (0.79, 3.17), (1.59, 2.70), (4.44, 0.79), (4.29, 2.30), (4.44, 2.78), (0.32, 3.89), (0.00, 4.44), (-0.32, 5.71), (-0.40, 7.14), (-0.56, 7.78)],
    [(-2.22, 5.71), (-1.59, 5.87), (-1.35, 6.59), (-1.75, 7.30), (-2.30, 7.22), (-2.54, 7.22)],
    [(8.17, 7.30), (8.17, 8.49), (7.38, 9.05), (5.08, 9.52), (1.03, 9.29), (-1.03, 9.29), (-2.38, 9.21), (-3.10, 8.89), (-3.17, 7.46), (-2.78, 8.02), (-1.51, 8.25), (0.40, 8.25), (3.89, 8.41), (5.48, 8.25), (7.62, 7.78)],
]
LEG_LOWER_DETAILS = [[(round(x/0.5, 2), round(-y/0.35, 2)) for x, y in shape] for shape in LEG_LOWER_DETAILS]

BODY_DETAILS=[
    ((0, 0, 0), (0, 0, 0),
    [
        [(-12.54, 42.38), (-3.34, 43.18), (7.3, 43.66), (18.58, 43.02), (28.26, 41.74), (31.9, 40.32), (33.5, 39.52), (32.86, 39.68), (28.26, 41.26), (19.2, 42.7), (7.46, 43.18), (-3.02, 43.02), (-12.22, 42.38)],
        [(-9.52, 26.98), (-5.08, 24.12), (0.32, 21.74), (6.66, 20.96), (6.2, 18.58), (3.34, 17.46), (-0.32, 18.88), (-6.2, 23.02), (-9.36, 24.44)],
        [(-13.8, 24.6), (-9.2, 24.28), (-6.98, 22.22), (-5.4, 17.78), (-6.2, 12.7), (-8.74, 9.36), (-11.42, 8.88), (-10.96, 16.04), (-9.2, 20.64), (-11.12, 23.66)],
        [(7.46, 20.8), (10.48, 21.12), (11.12, 11.74)],
        [(-10.8, -1.58), (-6.66, -0.48), (-3.5, 1.42), (-0.32, 4.6), (1.42, 7.62), (10.48, 7.78), (11.74, 5.4), (12.86, 2.54), (-3.34, 1.26), (-6.82, -0.8)],
        [(22.38, -10.32), (25.24, -11.74), (28.26, -17.62), (28.1, -21.12), (26.2, -23.66), (24.12, -24.92), (23.34, -24.28), (22.22, -24.28), (21.26, -23.18), (23.8, -20.8), (22.7, -19.84), (22.54, -18.42), (19.52, -20.16), (19.04, -17.78), (19.68, -16.34), (20.32, -12.54)],
        [(-17.46, -23.18), (-15.24, -21.58), (-9.84, -15.88), (-7.78, -14.76), (-7.62, -15.88), (-5.08, -17.62), (-4.28, -18.88), (-3.5, -22.7), (-4.28, -24.12), (-2.7, -26.04), (-4.6, -29.36), (-12.54, -29.84), (-13.8, -29.36), (-16.34, -26.04), (-16.82, -24.76), (-16.66, -24.12)],
        [(-26.34, 7.94), (-25.72, 9.04), (-24.44, 9.68), (-23.96, 8.58), (-24.92, 7.46), (-25.56, 7.3)],
        [(-8.1, -11.58), (-2.22, -18.42), (-1.58, -20.32), (-1.26, -21.74), (-2.86, -23.02), (-4.76, -22.7), (-6.66, -19.84)],
    ]),

    ((0.31, 0.52, 0.27), (0.31, 0.52, 0.27),
    [
        [(-7.46, 43.02), (8.42, 43.18), (-2.86, 33.96)],
        [(24.12, 41.9), (32.7, 40.0), (27.14, 33.66)],
    ]),

    ((0.72, 0.72, 0.72), (0.72, 0.72, 0.72),
    [
        [(-14.28, 5.56), (-6.82, -14.12), (-11.26, -2.22)],
        [(10.64, 11.58), (15.72, -11.74), (15.4, -2.22)],
        [(-0.8, -23.18), (3.66, -22.22), (9.52, -18.88), (12.7, -15.56), (15.56, -11.9), (14.28, -16.04), (12.06, -19.2), (8.74, -21.74), (5.24, -23.02), (1.74, -23.5)],
    ]),
]

LEG_DOWN = -8/SCALE
LEG_W, LEG_H = 8/SCALE, 34/SCALE

VIEWPORT_W = 600
VIEWPORT_H = 400

TERRAIN_STEP   = 14/SCALE
TERRAIN_LENGTH = 200     # in steps
TERRAIN_HEIGHT = VIEWPORT_H/SCALE/4
TERRAIN_GRASS    = 10    # low long are grass spots, in steps
TERRAIN_STARTPAD = 20    # in steps
FRICTION = 2.5

class ContactDetector(contactListener):
    def __init__(self, env):
        contactListener.__init__(self)
        self.env = env
    def BeginContact(self, contact):
        if self.env.body==contact.fixtureA.body or self.env.body==contact.fixtureB.body:
            self.env.game_over = True
        for leg in [self.env.legs[1], self.env.legs[3]]:
            if leg in [contact.fixtureA.body, contact.fixtureB.body]:
                leg.ground_contact = True
    def EndContact(self, contact):
        for leg in [self.env.legs[1], self.env.legs[3]]:
            if leg in [contact.fixtureA.body, contact.fixtureB.body]:
                leg.ground_contact = False

class Marvin(gym.Env):
    metadata = {
        'render.modes': ['human', 'rgb_array'],
        'video.frames_per_second' : FPS
    }

    def __init__(self):
        self._seed()
        self.viewer = None

        self.world = Box2D.b2World()
        self.terrain = None
        self.body = None

        self.prev_shaping = None
        self.reset()

        high = np.array([np.inf]*24)
        self.action_space = spaces.Box(np.array([-1,-1,-1,-1]), np.array([+1,+1,+1,+1]), dtype=np.float32)
        self.observation_space = spaces.Box(-high, high, dtype=np.float32)

    def _seed(self, seed=None):
        self.np_random, seed = seeding.np_random(seed)
        return [seed]

    def _destroy(self):
        if not self.terrain: return
        self.world.contactListener = None
        for t in self.terrain:
            self.world.DestroyBody(t)
        self.terrain = []
        self.world.DestroyBody(self.body)
        self.body = None
        for leg in self.legs:
            self.world.DestroyBody(leg)
        for detail in self.details:
            self.world.DestroyBody(detail)
        self.legs = []
        self.joints = []
        self.details = []

    def _generate_terrain(self):
        GRASS, STUMP, STAIRS, PIT, _STATES_ = range(5)
        state    = GRASS
        velocity = 0.0
        y        = TERRAIN_HEIGHT
        counter  = TERRAIN_STARTPAD
        oneshot  = False
        self.terrain   = []
        self.terrain_x = []
        self.terrain_y = []
        for i in range(TERRAIN_LENGTH):
            x = i*TERRAIN_STEP
            self.terrain_x.append(x)

            if state==GRASS and not oneshot:
                velocity = 0.8*velocity + 0.01*np.sign(TERRAIN_HEIGHT - y)
                if i > TERRAIN_STARTPAD: velocity += self.np_random.uniform(-1, 1)/SCALE   #1
                y += velocity

            elif state==PIT and oneshot:
                counter = self.np_random.randint(3, 5)
                poly = [
                    (x,              y),
                    (x+TERRAIN_STEP, y),
                    (x+TERRAIN_STEP, y-4*TERRAIN_STEP),
                    (x,              y-4*TERRAIN_STEP),
                    ]
                t = self.world.CreateStaticBody(
                    fixtures = fixtureDef(
                        shape=polygonShape(vertices=poly),
                        friction = FRICTION
                    ))
                t.color1, t.color2 = (1,1,1), (0.6,0.6,0.6)
                self.terrain.append(t)
                t = self.world.CreateStaticBody(
                    fixtures = fixtureDef(
                        shape=polygonShape(vertices=[(p[0]+TERRAIN_STEP*counter,p[1]) for p in poly]),
                        friction = FRICTION
                    ))
                t.color1, t.color2 = (1,1,1), (0.6,0.6,0.6)
                self.terrain.append(t)
                counter += 2
                original_y = y

            elif state==PIT and not oneshot:
                y = original_y
                if counter > 1:
                    y -= 4*TERRAIN_STEP

            elif state==STUMP and oneshot:
                counter = self.np_random.randint(1, 3)
                poly = [
                    (x,                      y),
                    (x+counter*TERRAIN_STEP, y),
                    (x+counter*TERRAIN_STEP, y+counter*TERRAIN_STEP),
                    (x,                      y+counter*TERRAIN_STEP),
                    ]
                t = self.world.CreateStaticBody(
                    fixtures = fixtureDef(
                        shape=polygonShape(vertices=poly),
                        friction = FRICTION
                    ))
                t.color1, t.color2 = (1,1,1), (0.6,0.6,0.6)
                self.terrain.append(t)

            elif state==STAIRS and oneshot:
                stair_height = +1 if self.np_random.rand() > 0.5 else -1
                stair_width = self.np_random.randint(4, 5)
                stair_steps = self.np_random.randint(3, 5)
                original_y = y
                for s in range(stair_steps):
                    poly = [
                        (x+(    s*stair_width)*TERRAIN_STEP, y+(   s*stair_height)*TERRAIN_STEP),
                        (x+((1+s)*stair_width)*TERRAIN_STEP, y+(   s*stair_height)*TERRAIN_STEP),
                        (x+((1+s)*stair_width)*TERRAIN_STEP, y+(-1+s*stair_height)*TERRAIN_STEP),
                        (x+(    s*stair_width)*TERRAIN_STEP, y+(-1+s*stair_height)*TERRAIN_STEP),
                        ]
                    t = self.world.CreateStaticBody(
                        fixtures = fixtureDef(
                            shape=polygonShape(vertices=poly),
                            friction = FRICTION
                        ))
                    t.color1, t.color2 = (1,1,1), (0.6,0.6,0.6)
                    self.terrain.append(t)
                counter = stair_steps*stair_width

            elif state==STAIRS and not oneshot:
                s = stair_steps*stair_width - counter - stair_height
                n = s/stair_width
                y = original_y + (n*stair_height)*TERRAIN_STEP

            oneshot = False
            self.terrain_y.append(y)
            counter -= 1
            if counter==0:
                counter = self.np_random.randint(TERRAIN_GRASS/2, TERRAIN_GRASS)
                state = GRASS
                oneshot = True

        self.terrain_poly = []
        for i in range(TERRAIN_LENGTH-1):
            poly = [
                (self.terrain_x[i],   self.terrain_y[i]),
                (self.terrain_x[i+1], self.terrain_y[i+1])
                ]
            t = self.world.CreateStaticBody(
                fixtures = fixtureDef(
                    shape=edgeShape(vertices=poly),
                    friction = FRICTION,
                    categoryBits=0x0001,
                ))
            color = (0.5, 0.6, 0.7)
            t.color1 = color
            t.color2 = color
            self.terrain.append(t)
            color = (0.5, 0.6, 0.7)
            poly += [ (poly[1][0], 0), (poly[0][0], 0) ]
            self.terrain_poly.append( (poly, color) )
        self.terrain.reverse()

    def _generate_clouds(self):
        # Sorry for the clouds, couldn't resist
        self.cloud_poly   = []
        for i in range(TERRAIN_LENGTH//20):
            x = self.np_random.uniform(0, TERRAIN_LENGTH)*TERRAIN_STEP
            y = VIEWPORT_H/SCALE*3/4
            poly = [
                (x+15*TERRAIN_STEP*math.sin(3.14*2*a/5)+self.np_random.uniform(0,5*TERRAIN_STEP),
                 y+ 5*TERRAIN_STEP*math.cos(3.14*2*a/5)+self.np_random.uniform(0,5*TERRAIN_STEP) )
                for a in range(5) ]
            x1 = min( [p[0] for p in poly] )
            x2 = max( [p[0] for p in poly] )
            self.cloud_poly.append( (poly,x1,x2) )

    def reset(self):
        self._destroy()
        self.world.contactListener_bug_workaround = ContactDetector(self)
        self.world.contactListener = self.world.contactListener_bug_workaround
        self.game_over = False
        self.prev_shaping = None
        self.scroll = 0.0
        self.lidar_render = 0

        W = VIEWPORT_W/SCALE
        H = VIEWPORT_H/SCALE

        self._generate_terrain()
        self._generate_clouds()

        init_x = TERRAIN_STEP*TERRAIN_STARTPAD/2
        init_y = TERRAIN_HEIGHT+3*LEG_H
        self.body = self.world.CreateDynamicBody(
            position = (init_x, init_y),
            fixtures = fixtureDef(
                shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in BODY_SHAPE[-1] ]),
                density=0.5,
                friction=0.1,
                categoryBits=0x0020,
                maskBits=0x001,  # collide only with ground
                restitution=0.0) # 0.99 bouncy
                )
        for shape in BODY_SHAPE[:-1]:
            self.body.CreateFixture(fixtureDef(
                shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in shape ]),
                density=0.5,
                friction=0.1,
                categoryBits=0x0020,
                maskBits=0x001,  # collide only with ground
                restitution=0.0) # 0.99 bouncy
                )
        self.body.color1 = (0.9,0.9,0.9)
        self.body.color2 = (0.9,0.9,0.9)
        self.body.ApplyForceToCenter((self.np_random.uniform(-INITIAL_RANDOM, INITIAL_RANDOM), 0), True)

        self.details = []
        detailsJoints = []

        for color1, color2, shapes in BODY_DETAILS:
            detail = self.world.CreateDynamicBody(
                position = (init_x,init_y),
                fixtures=fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in shapes[0] ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                )
            )

            for shape in shapes:
                another = detail.CreateFixture(fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in shape ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                ))

            detail.color1 = color1
            detail.color2 = color2
            self.details.append(detail)

            joint = weldJointDef(
                bodyA=detail,
                bodyB=self.body,
                localAnchorA=(0,0),
                localAnchorB=(0,0),
            )
            detailsJoints.append(self.world.CreateJoint(joint))


        self.legs = []
        self.joints = []
        for i in [-1,+1]:
            leg_upper = self.world.CreateDynamicBody(
                position = (init_x, init_y - LEG_H/2 - LEG_DOWN),
                angle = (i*0.05),
                fixtures = fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in LEG_UPPER_SHAPE ]),
                    density=0.5,
                    restitution=0.0,
                    categoryBits=0x0020,
                    maskBits=0x001)
                )
            leg_upper.color1 = (0.9,0.9,0.9)
            leg_upper.color2 = (0.9,0.9,0.9)
            rjd = revoluteJointDef(
                bodyA=self.body,
                bodyB=leg_upper,
                localAnchorA=(0, LEG_DOWN),
                localAnchorB=(0, LEG_H/2),
                enableMotor=True,
                enableLimit=True,
                maxMotorTorque=MOTORS_TORQUE,
                motorSpeed = 2*i,
                lowerAngle = -0.8,
                upperAngle = 1.1,
                )
            self.joints.append(self.world.CreateJoint(rjd))

            leg_lower = self.world.CreateDynamicBody(
                position = (init_x, init_y - LEG_H*3/2 - LEG_DOWN),
                angle = (i*0.05),
                fixtures = fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in LEG_LOWER_SHAPE ]),
                    density=0.5,
                    restitution=0.0,
                    categoryBits=0x0020,
                    maskBits=0x001)
                )
            leg_lower.color1 = (0.9,0.9,0.9)
            leg_lower.color2 = (0.9,0.9,0.9)
            rjd = revoluteJointDef(
                bodyA=leg_upper,
                bodyB=leg_lower,
                localAnchorA=(0, -LEG_H/3),
                localAnchorB=(0, LEG_H/3),
                enableMotor=True,
                enableLimit=True,
                maxMotorTorque=MOTORS_TORQUE,
                motorSpeed = 1,
                lowerAngle = -1.6,
                upperAngle = -0.1,
                )
            leg_lower.ground_contact = False
            self.joints.append(self.world.CreateJoint(rjd))

            detail_upper = self.world.CreateDynamicBody(
                position = (init_x, init_y - LEG_H/2 - LEG_DOWN),
                fixtures=fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in LEG_UPPER_DETAILS[0] ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                )
            )

            for shape in LEG_UPPER_DETAILS[1:]:
                another = detail_upper.CreateFixture(fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in shape ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                ))

            detail_upper.color1 = (0,0,0)
            detail_upper.color2 = (0,0,0)

            joint = weldJointDef(
                bodyA=detail_upper,
                bodyB=leg_upper,
                localAnchorA=(0,0),
                localAnchorB=(0,0),
            )
            detailsJoints.append(self.world.CreateJoint(joint))

            detail_lower = self.world.CreateDynamicBody(
                position = (init_x, init_y - LEG_H/2 - LEG_DOWN),
                fixtures=fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in LEG_LOWER_DETAILS[0] ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                )
            )

            for shape in LEG_LOWER_DETAILS[1:]:
                another = detail_lower.CreateFixture(fixtureDef(
                    shape=polygonShape(vertices=[ (x/SCALE,y/SCALE) for x,y in shape ]),
                    density=0.0001,
                    categoryBits=0x0020,
                    maskBits=0x001,
                    restitution=0.0
                ))

            detail_lower.color1 = (0,0,0)
            detail_lower.color2 = (0,0,0)

            joint = weldJointDef(
                bodyA=detail_lower,
                bodyB=leg_lower,
                localAnchorA=(0,0),
                localAnchorB=(0,0),
            )
            detailsJoints.append(self.world.CreateJoint(joint))


            self.details.append(detail_lower)
            self.details.append(detail_upper)
            self.legs.append(leg_upper)
            self.legs.append(leg_lower)


        self.joints.extend(detailsJoints)

        self.drawlist = self.terrain + self.legs[::-1] + [self.body] + self.details

        class LidarCallback(Box2D.b2.rayCastCallback):
            def ReportFixture(self, fixture, point, normal, fraction):
                if (fixture.filterData.categoryBits & 1) == 0:
                    return 1
                self.p2 = point
                self.fraction = fraction
                return 0
        self.lidar = [LidarCallback() for _ in range(10)]

        return self.step(np.array([0,0,0,0]))[0]

    def step(self, action):
        #self.body.ApplyForceToCenter((0, 20), True) -- Uncomment this to receive a bit of stability help
        control_speed = False  # Should be easier as well
        if control_speed:
            self.joints[0].motorSpeed = float(SPEED_HIP  * np.clip(action[0], -1, 1))
            self.joints[1].motorSpeed = float(SPEED_KNEE * np.clip(action[1], -1, 1))
            self.joints[2].motorSpeed = float(SPEED_HIP  * np.clip(action[2], -1, 1))
            self.joints[3].motorSpeed = float(SPEED_KNEE * np.clip(action[3], -1, 1))
        else:
            self.joints[0].motorSpeed     = float(SPEED_HIP     * np.sign(action[0]))
            self.joints[0].maxMotorTorque = float(MOTORS_TORQUE * np.clip(np.abs(action[0]), 0, 1))
            self.joints[1].motorSpeed     = float(SPEED_KNEE    * np.sign(action[1]))
            self.joints[1].maxMotorTorque = float(MOTORS_TORQUE * np.clip(np.abs(action[1]), 0, 1))
            self.joints[2].motorSpeed     = float(SPEED_HIP     * np.sign(action[2]))
            self.joints[2].maxMotorTorque = float(MOTORS_TORQUE * np.clip(np.abs(action[2]), 0, 1))
            self.joints[3].motorSpeed     = float(SPEED_KNEE    * np.sign(action[3]))
            self.joints[3].maxMotorTorque = float(MOTORS_TORQUE * np.clip(np.abs(action[3]), 0, 1))

        self.world.Step(1.0/FPS, 6*30, 2*30)

        pos = self.body.position
        vel = self.body.linearVelocity

        for i in range(10):
            self.lidar[i].fraction = 1.0
            self.lidar[i].p1 = pos
            self.lidar[i].p2 = (
                pos[0] + math.sin(1.5*i/10.0)*LIDAR_RANGE,
                pos[1] - math.cos(1.5*i/10.0)*LIDAR_RANGE)
            self.world.RayCast(self.lidar[i], self.lidar[i].p1, self.lidar[i].p2)

        state = [
            self.body.angle,        # Normal angles up to 0.5 here, but sure more is possible.
            2.0*self.body.angularVelocity/FPS,
            0.3*vel.x*(VIEWPORT_W/SCALE)/FPS,  # Normalized to get -1..1 range
            0.3*vel.y*(VIEWPORT_H/SCALE)/FPS,
            self.joints[0].angle,   # This will give 1.1 on high up, but it's still OK (and there should be spikes on hiting the ground, that's normal too)
            self.joints[0].speed / SPEED_HIP,
            self.joints[1].angle + 1.0,
            self.joints[1].speed / SPEED_KNEE,
            1.0 if self.legs[1].ground_contact else 0.0,
            self.joints[2].angle,
            self.joints[2].speed / SPEED_HIP,
            self.joints[3].angle + 1.0,
            self.joints[3].speed / SPEED_KNEE,
            1.0 if self.legs[3].ground_contact else 0.0
            ]
        state += [l.fraction for l in self.lidar]
        assert len(state)==24

        self.scroll = pos.x - VIEWPORT_W/SCALE/5

        shaping  = 130*pos[0]/SCALE   # moving forward is a way to receive reward (normalized to get 300 on completion)
        shaping -= 5.0*abs(state[0])  # keep head straight, other than that and falling, any behavior is unpunished

        reward = 0
        if self.prev_shaping is not None:
            reward = shaping - self.prev_shaping
        self.prev_shaping = shaping

        for a in action:
            reward -= 0.00035 * MOTORS_TORQUE * np.clip(np.abs(a), 0, 1)
            # normalized to about -50.0 using heuristic, more optimal agent should spend less

        done = False
        if self.game_over or pos[0] < 0:
            reward = -100
            done   = True
        if pos[0] > (TERRAIN_LENGTH-TERRAIN_GRASS)*TERRAIN_STEP:
            done   = True
        return np.array(state), reward, done, {}

    def render(self, mode='human', close=False):
        if close:
            if self.viewer is not None:
                self.viewer.close()
                self.viewer = None
            return

        from gym.envs.classic_control import rendering
        if self.viewer is None:
            self.viewer = rendering.Viewer(VIEWPORT_W, VIEWPORT_H)
        self.viewer.set_bounds(self.scroll, VIEWPORT_W/SCALE + self.scroll, 0, VIEWPORT_H/SCALE)

        self.viewer.draw_polygon( [
            (self.scroll,                  0),
            (self.scroll+VIEWPORT_W/SCALE, 0),
            (self.scroll+VIEWPORT_W/SCALE, VIEWPORT_H/SCALE),
            (self.scroll,                  VIEWPORT_H/SCALE),
            ], color=(0.23, 0.14, 0.47) )
        for poly,x1,x2 in self.cloud_poly:
            if x2 < self.scroll/2: continue
            if x1 > self.scroll/2 + VIEWPORT_W/SCALE: continue
            self.viewer.draw_polygon( [(p[0]+self.scroll/2, p[1]) for p in poly], color=(0.34,0.29,0.5))
        for poly, color in self.terrain_poly:
            if poly[1][0] < self.scroll: continue
            if poly[0][0] > self.scroll + VIEWPORT_W/SCALE: continue
            self.viewer.draw_polygon(poly, color=color)

        self.lidar_render = (self.lidar_render+1) % 100
        i = self.lidar_render
        if i < 2*len(self.lidar):
            l = self.lidar[i] if i < len(self.lidar) else self.lidar[len(self.lidar)-i-1]
            self.viewer.draw_polyline( [l.p1, l.p2], color=(1,0,0), linewidth=1 )

        for obj in self.drawlist:
            for f in obj.fixtures:
                trans = f.body.transform
                if type(f.shape) is circleShape:
                    t = rendering.Transform(translation=trans*f.shape.pos)
                    self.viewer.draw_circle(f.shape.radius, 30, color=obj.color1).add_attr(t)
                    self.viewer.draw_circle(f.shape.radius, 30, color=obj.color2, filled=False, linewidth=2).add_attr(t)
                else:
                    path = [trans*v for v in f.shape.vertices]
                    self.viewer.draw_polygon(path, color=obj.color1)
                    path.append(path[0])
                    self.viewer.draw_polyline(path, color=obj.color2, linewidth=2)

        flagy1 = TERRAIN_HEIGHT
        flagy2 = flagy1 + 50/SCALE
        x = TERRAIN_STEP*3
        self.viewer.draw_polyline( [(x, flagy1), (x, flagy2)], color=(0,0,0), linewidth=2 )
        f = [(x, flagy2), (x, flagy2-10/SCALE), (x+25/SCALE, flagy2-5/SCALE)]
        self.viewer.draw_polygon(f, color=(0.9,0.2,0) )
        self.viewer.draw_polyline(f + [f[0]], color=(0,0,0), linewidth=2 )

        return self.viewer.render(return_rgb_array = mode=='rgb_array')
