//
//  ViewController.swift
//  Gravitatem
//
//  Created by Siddhant Jain on 2015-05-19.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UICollisionBehaviorDelegate {
    var animator: UIDynamicAnimator!
    var gravity: UIGravityBehavior!
    var collision: UICollisionBehavior!
    
    override func viewDidLoad() {
        let square = UIView(frame: CGRect(x: 100, y: 100, width: 100, height: 100))
        square.backgroundColor = UIColor.purpleColor()
        view.addSubview(square)
        
        let barrier = UIView(frame: CGRect(x: 0, y: 300, width: 130, height: 20))
        barrier.backgroundColor = UIColor.redColor()
        view.addSubview(barrier)
        
        
        animator = UIDynamicAnimator(referenceView: view)
        gravity = UIGravityBehavior(items: [square])
        animator.addBehavior(gravity)
        
       
        //collision = UICollisionBehavior(items: [square, barrier])
        
        collision = UICollisionBehavior(items: [square, barrier])
       collision.collisionDelegate = self
        
        
        
        collision.addBoundaryWithIdentifier("barrier", forPath: UIBezierPath(rect: barrier.frame))
        collision.translatesReferenceBoundsIntoBoundary = true
        animator.addBehavior(collision)
        
        let itemBehaviour = UIDynamicItemBehavior(items: [square, barrier])
        itemBehaviour.elasticity = 1.2
        animator.addBehavior(itemBehaviour)
        
        
        
    }
    func collisionBehavior(behavior: UICollisionBehavior!, beganContactForItem item: UIDynamicItem, withBoundaryIdentifier identifier: NSCopying!, atPoint p: CGPoint) {
        println("Boundary contact occurred - \(identifier)")
        
        let collidingView = item as! UIView
        collidingView.backgroundColor = UIColor.yellowColor()
    
        UIView.animateWithDuration(0.3) {
            collidingView.backgroundColor = UIColor.purpleColor()
        }
    }
        
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

