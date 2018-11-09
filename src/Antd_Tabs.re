[@bs.module] external tabs: ReasonReact.reactClass = "antd/lib/tabs";

[%bs.raw {|require("antd/lib/tabs/style")|}];

[@bs.deriving jsConverter]
type tabsType = [ | `line | `card | [@bs.as "editable-card"] `editableCard ];
[@bs.deriving jsConverter]
type tabsPosition = [ | `top | `right | `bottom | `left ];
[@bs.deriving jsConverter]
type tabSize = [ | `large | `default | `small ];

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional] activeKey: string,
  [@bs.optional] defaultActiveKey: string,
  [@bs.optional] hideAdd: bool,
  [@bs.optional] onChange: (~activeKey: string) => unit,
  [@bs.optional] onTabClick: ReactEvent.Mouse.t => unit,
  [@bs.optional] onPrevClick: ReactEvent.Mouse.t => unit,
  [@bs.optional] onNextClick: ReactEvent.Mouse.t => unit,
  [@bs.optional] tabBarExtraContent: ReasonReact.reactElement,
  [@bs.optional] tabBarStyle: ReactDOMRe.Style.t,
  [@bs.optional] [@bs.as "type"] _type: tabsType,
  [@bs.optional] tabPosition: tabsPosition,
  /* TODO */
  /* [@bs.optional] onEdit: (~targetKey: string | React.MouseEvent<HTMLElement>, action: any) => void, */
  [@bs.optional] size: tabSize,
  [@bs.optional] style: ReactDOMRe.Style.t,
  [@bs.optional] prefixCls: string,
  [@bs.optional] className: string,
  /* TODO */
  /* [@bs.optional] animated: boolean | { inkBar: boolean; tabPane: boolean; }, */
  [@bs.optional] tabBarGutter: float,
  /* TODO */
  /* [@bs.optional] renderTabBar: (props: TabsProps, DefaultTabBar: React.ReactNode) => React.ReactElement<any>, */
}

let make =
    (
      ~activeKey=?,
      ~defaultActiveKey=?,
      ~hideAdd=?,
      ~onChange=?,
      ~onTabClick=?,
      ~onPrevClick=?,
      ~onNextClick=?,
      ~tabBarExtraContent=?,
      ~tabBarStyle=?,
      ~_type=?,
      ~tabPosition=?,
      ~size=?,
      ~style=?,
      ~prefixCls=?,
      ~className=?,
      ~tabBarGutter=?,
      ~children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabs,
    ~props=
      jsProps(
        ~activeKey?,
        ~defaultActiveKey?,
        ~hideAdd?,
        ~onChange?,
        ~onTabClick?,
        ~onPrevClick?,
        ~onNextClick?,
        ~tabBarExtraContent?,
        ~tabBarStyle?,
        ~_type?,
        ~tabPosition?,
        ~size?,
        ~style?,
        ~prefixCls?,
        ~className?,
        ~tabBarGutter?,
        (),
      ),
    children,
  );
